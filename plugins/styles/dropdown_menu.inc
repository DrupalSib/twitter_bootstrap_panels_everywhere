<?php

/**
 * @file
 * Definition of the 'dropdown_menu' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap dropdown menu'),
  'description' => t('Render menus in twitter bootstrap dropdown manner.'),
  'render pane' => 'twitter_bootstrap_dropdown_menu_style_render_pane',
  'pane settings form' => 'twitter_bootstrap_dropdown_menu_style_settings_form',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function twitter_bootstrap_twitter_bootstrap_dropdown_menu_style_render_pane($variables) {
  $content = $variables['content'];
  $content->content['#theme_wrappers'] = array('twitter_bootstrap_btn_dropdown_menu_wrapper');
  $content->content = theme('twitter_bootstrap_btn_dropdown', array(
    'links' => render($content->content),
    'label' => $content->title,
    'type' => !empty($variables['settings']['button_type']) ? $variables['settings']['button_type'] : 'success',
    'attributes' => array(),
    'heading' => array(
      'text' => t('Secondary menu'),
      'level' => 'h2',
      'class' => array('element-invisible'),
    ),
  ));

  // Wipe title to avoid it duplication in default template.
  $content->title = '';
  $output = theme('panels_pane', array('content' => $content, 'pane' => $variables['pane'], 'display' => $variables['display']));
  return $output;
}

/**
 * Settings form callback.
 */
function twitter_bootstrap_dropdown_menu_style_settings_form($style_settings) {
  $form['button_type'] = array(
    '#type' => 'radios',
    '#title' => t('Button type'),
    '#options' => twitter_bootstrap_get_button_types(),
    '#default_value' => (isset($style_settings['button_type'])) ? $style_settings['button_type'] : 'success',
  );

  return $form;
}

