<?php
/**
 * @file
 * Settings page logic and view.
 */

/**
 * User settings form.
 */
function custom_settings_form($form, &$form_state) {
  $form['test'] = [
    '#markup' => 'Coming soon.',
  ];

  return $form;
}
