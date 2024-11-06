<?php
/**
 * @file
 * Layout context handler for entities.
 */
class CommerceReportsDashboardLayoutContext extends LayoutContext {
  var $usageType = LayoutContext::USAGE_TYPE_SYSTEM;

  /**
   * Return the indicator for this context.
   */
  function type() {
    return 'commerce_reports_dashboard';
  }

  /**
   * Assemble a human-readable label of this object.
   */
  function label() {
    return t('Commerce Reports Dashboard');
  }
}
