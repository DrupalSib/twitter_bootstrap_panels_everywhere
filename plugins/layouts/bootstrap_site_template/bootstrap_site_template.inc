<?php

/**
 * implementation of hook_panels_layouts()
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap site template'),
  'category' => t('Twitter bootstrap'),
  'icon' => 'bootstrap_site_template.png',
  'theme' => 'bootstrap_site_template',
  'css' => 'bootstrap-site-template.css',
  'admin css' => 'bootstrap-site-template-admin.css',
  'regions' => array(
    'sticky_bar_logo' => t('Sticky logo'),
    'sticky_bar_navigation_left' => t('Sticky navigation left'),
    'sticky_bar_navigation_right' => t('Sticky navigation right'),
    'header' => t('Top Bar'),
    'highlighted' => t('Highlighted'),
    'help' => t('Help'),
    'content' => t('Content'),
    'content_top' => t('Content top'),
    'sidebar_first' => t('Primary'),
    'sidebar_second' => t('Secondary'),
    'footer' => t('Footer'),
  ),
);

/**
 * Preprocess variables for bootstrap-site-template.tpl.php
 *
 * @see bootstrap-site-template.tpl.php
 */
function template_preprocess_bootstrap_site_template(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['content']['sidebar_first']) && !empty($variables['content']['sidebar_second'])) {
    $variables['columns'] = 3;
  }
  elseif (!empty($variables['content']['sidebar_first']) || !empty($variables['content']['sidebar_second'])) {
    $variables['columns'] = 2;
  }
  else {
    $variables['columns'] = 1;
  }

  switch($variables['columns']) {
    case 1:
      $class = 'span12';
      break;
    case 2:
      $class = 'span9';
      break;
    case 3:
      $class = 'span6';
      break;
  }
  $variables['content_region_class'] = $class;
}