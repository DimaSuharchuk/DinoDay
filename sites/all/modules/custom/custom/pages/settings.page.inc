<?php

/**
 * @file
 * Settings page logic and view.
 */

/**
 * User settings form.
 *
 * {@inheritdoc}
 */
function custom_settings_form($form, &$form_state) {
  $form['temporary'] = [
    '#markup' => 'Coming soon.',
  ];

  return $form;
}
