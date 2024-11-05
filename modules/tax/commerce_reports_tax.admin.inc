<?php
/**
 * @file
 * Administrative forms.
 */

/**
 * Configuration form.
 */
function commerce_reports_tax_form($form, &$form_state) {
  $config = config('commerce_reports_tax.settings');
  $options = array();

  $statuses = commerce_order_statuses();
  foreach ($statuses as $status) {
    $options[$status['name']] = check_plain($status['title']);
  }

  $form['#config'] = 'commerce_reports_tax.settings';
  $form['commerce_reports_tax_order_statuses']          = array(
    '#type'          => 'select',
    '#multiple'      => TRUE,
    '#title'         => t('Order statuses'),
    '#description'   => t('Statuses for which tax will be calculated.'),
    '#options'       => $options,
    '#default_value' => $config->get('commerce_reports_tax_order_statuses'),
  );
  $form['commerce_reports_tax_order_generate_statuses'] = array(
    '#type'          => 'select',
    '#multiple'      => TRUE,
    '#title'         => t('Generate Order statuses'),
    '#description'   => t('Statuses for which tax will be generated.'),
    '#options'       => $options,
    '#default_value' => $config->get('commerce_reports_tax_order_generate_statuses'),
  );

  $form['generate'] = array(
    '#type'   => 'submit',
    '#value'  => t('Generate all tax information'),
    '#submit' => array(
      'system_settings_form_submit',
      'commerce_reports_tax_form_submit_generate',
    ),
  );

  return system_settings_form($form);
}

/**
 * Submit handler that generates a tax report.
 */
function commerce_reports_tax_form_submit_generate($form, &$form_state) {
  commerce_reports_tax_generate();
}

/**
 * Callback for tax report generation.
 */
function commerce_reports_tax_generate_callback() {
  commerce_reports_tax_generate();

  batch_process('admin/commerce/reports/tax');
}

/**
 * Returns the table containing the tax report.
 */
function commerce_reports_tax_table($start = 0, $end = REQUEST_TIME) {
  $config = config('commerce_reports_tax.settings');
  if (!state_get('commerce_reports_tax_batch_finished', FALSE)) {
    backdrop_set_message();
  }

  $rows = commerce_reports_tax($start, $end);

  if (!state_get('commerce_reports_tax_batch_finished', FALSE)) {
    $rows = array();

    $rows[] = array(
      'data' => array(
        array(
          'data' => t("It seems you have not yet extracted tax information from orders that occurred before enabling the tax reporting module. You will have to <a href='@generate-url'>generate</a> past data before anything will show up.", array('@generate-url' => url('admin/commerce/config/tax-reports/generate'))),
          'colspan' => 3,
        ),
      ),
    );
  }
  elseif (!$rows) {
    $rows[] = array(
      'data' => array(
        array(
          'data' => t("There's currently no tax data available. You might want to <a href='@generate-url'>generate</a> past data.", array('@generate-url' => url('admin/commerce/config/tax-reports/generate'))),
          'colspan' => 3,
        ),
      ),
    );
  }

  return array(
    '#theme'  => 'table',
    '#header' => array(t('Tax rate'), t('Taxable'), t('Taxed')),
    '#rows'   => $rows,
  );
}
