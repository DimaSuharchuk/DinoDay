<?php
/**
 * @file
 * Site configurations or global variables.
 */

/**
 * Global variables.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function site_settings_form($form, &$form_state) {
  $form['timer_duration'] = [
    '#type' => 'textfield',
    '#title' => t('Timer duration'),
    '#description' => t('Float number in minutes. For example: 0.5 or 30'),
    '#default_value' => variable_get('timer_duration'),
  ];

  return system_settings_form($form);
}
