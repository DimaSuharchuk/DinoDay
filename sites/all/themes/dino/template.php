<?php

/**
 * Implements template_preprocess_theme.
 *
 * {@inheritdoc}
 */
function dino_preprocess_dinosaur_info(&$variables) {
  global $user;

  $id = $variables['dinosaur_entity']->id;
  $user_dinosaurs = unserialize($user->dinosaurs);
  $current_dinosaur = $user_dinosaurs[$id];

  $variables['picture_path'] = $variables['dinosaur_entity']->picture;
  $variables['name'] = $variables['dinosaur_entity']->name;
  $variables['grade'] = $variables['dinosaur_entity']->grade;
  $variables['age'] = _get_past_time(time() - $current_dinosaur['caught']);
  $variables['food_type'] = $variables['dinosaur_entity']->food_type;
  $variables['favorite_food'] = $variables['dinosaur_entity']->favorite_food;

  $variables['health'] = $current_dinosaur['health'];
  $variables['satiety'] = $current_dinosaur['satiety'];
  $variables['mood'] = $current_dinosaur['mood'];
}

/**
 * Implements template_preprocess_theme.
 *
 * {@inheritdoc}
 */
function dino_preprocess_dinosaur_undefined_info(&$variables) {
  $variables['picture_path'] = _get_dinosaur_black_picture_path($variables['dinosaur_entity']->picture);
  $variables['grade'] = $variables['dinosaur_entity']->grade;
}
