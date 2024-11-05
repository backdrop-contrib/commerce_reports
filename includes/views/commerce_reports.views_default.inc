<?php
/**
 * @file
 * Default views.
 */

/**
 * Views for commerce orders for report displays.
 */
function commerce_reports_data_export($view) {
  if (empty($view->display['page']) || empty($view->display['page']->display_options['path'])) {
    return;
  }

  $handler = $view->new_display('views_data_export', 'Export to CSV', 'views_data_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = $view->display['page']->display_options['path'] . '/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
  );
}

