<?php
/**
 * @file
 * Catch dinosaurs functionality.
 */

/**
 * Implements hook_cronapi().
 */
function custom_cronapi($op, $job = NULL) {
  $items = [];

  $items['dinosaur_catch'] = [
    'description' => 'Every minute check for catch a dinosaur.',
    'rule' => '* * * * *',
    'callback' => 'custom_dinosaur_catch',
  ];

  return $items;
}

/**
 * Callback function for cron.
 * Catch dinosaurs and save to user.
 *
 * @throws \Exception
 */
function custom_dinosaur_catch() {
  // Get users that set a bait.
  $users_bait = db_select('users', 'u')
    ->fields('u', ['uid', 'catch'])
    ->condition('catch', 0, '!=')
    ->execute()
    ->fetchAllKeyed(0, 1);

  foreach ($users_bait as $uid => $food_id /* bait id. */) {
    // Get new dino id if caught.
    $id = _get_caught_dino_id($food_id);
    if ($id) {
      // Load current user who caught dino.
      $user = user_load($uid);
      // Get dinosaurs from user.
      $user_dinosaurs = $user->dinosaurs ? unserialize($user->dinosaurs) : [];
      // If user have not the dinosaur save it.
      if (!in_array($id, array_keys($user_dinosaurs))) {
        // Start stats.
        $dinosaur_info = [
          'caught' => time(),
          'life' => 100,
          'mood' => 100,
        ];

        $user_dinosaurs[$id] = $dinosaur_info;
        $user->dinosaurs = serialize($user_dinosaurs);
      }
      // Remove bait.
      $user->catch = 0;

      user_save($user);
    }
  }
}

/**
 * Helper function drop dinosaurs with some chance to accordance with bait rank.
 *
 * @param $bait_id
 *  Bait id of some rank.
 *  17: rank I
 *  18: rank II
 *  19: rank III
 *  20: rank IV
 *
 * @return bool|int
 *  Dino ID or FALSE.
 */
function _get_caught_dino_id($bait_id) {
  $min = 0;
  $max = 100000;

  $_1 = $max * 0.01; // 1%
  $_01 = $max * 0.001; // 0.1%
  $_001 = $max * 0.0001; // 0.01%
  $_0001 = $max * 0.00001; // 0.001%

  $random = rand($min, $max);

  switch ($bait_id) {
    case 17:
      if ($random >= $min && $random < $min + $_1) {
        return _get_random_dino_id_rank_I();
      }
      elseif ($random >= $min + $_1 && $random < $min + $_1 + $_01) {
        return _get_random_dino_id_rank_II();
      }
      elseif ($random >= $min + $_1 + $_01 && $random < $min + $_1 + $_01 + $_001) {
        return _get_random_dino_id_rank_III();
      }
      elseif ($random >= $min + $_1 + $_01 + $_001 && $random < $min + $_1 + $_01 + $_001 + $_0001) {
        return _get_random_dino_id_rank_IV();
      }
      break;

    case 18:
      if ($random >= $min && $random < $min + $_01) {
        return _get_random_dino_id_rank_I();
      }
      elseif ($random >= $min + $_01 && $random < $min + $_01 + $_1) {
        return _get_random_dino_id_rank_II();
      }
      elseif ($random >= $min + $_01 + $_1 && $random < $min + $_01 + $_1 + $_01) {
        return _get_random_dino_id_rank_III();
      }
      elseif ($random >= $min + $_01 + $_1 + $_01 && $random < $min + $_01 + $_1 + $_01 + $_001) {
        return _get_random_dino_id_rank_IV();
      }
      break;

    case 19:
      if ($random >= $min && $random < $min + $_001) {
        return _get_random_dino_id_rank_I();
      }
      elseif ($random >= $min + $_001 && $random < $min + $_001 + $_01) {
        return _get_random_dino_id_rank_II();
      }
      elseif ($random >= $min + $_001 + $_01 && $random < $min + $_001 + $_01 + $_1) {
        return _get_random_dino_id_rank_III();
      }
      elseif ($random >= $min + $_001 + $_01 + $_1 && $random < $min + $_001 + $_01 + $_1 + $_01) {
        return _get_random_dino_id_rank_IV();
      }
      break;

    case 20:
      if ($random >= $min && $random < $min + $_0001) {
        return _get_random_dino_id_rank_I();
      }
      elseif ($random >= $min + $_0001 && $random < $min + $_0001 + $_001) {
        return _get_random_dino_id_rank_II();
      }
      elseif ($random >= $min + $_0001 + $_001 && $random < $min + $_0001 + $_001 + $_01) {
        return _get_random_dino_id_rank_III();
      }
      elseif ($random >= $min + $_0001 + $_001 + $_01 && $random < $min + $_0001 + $_001 + $_01 + $_1) {
        return _get_random_dino_id_rank_IV();
      }
      break;
  }

  return FALSE;
}

/**
 * Helper function returns random dinosaur ID of I rank.
 *
 * @return int
 */
function _get_random_dino_id_rank_I() {
  return rand(1, 15);
}

/**
 * Helper function returns random dinosaur ID of II rank.
 *
 * @return int
 */
function _get_random_dino_id_rank_II() {
  return rand(16, 25);
}

/**
 * Helper function returns random dinosaur ID of III rank.
 *
 * @return int
 */
function _get_random_dino_id_rank_III() {
  return rand(26, 29);
}

/**
 * Helper function returns dinosaur ID of IV rank.
 *
 * @return int
 */
function _get_random_dino_id_rank_IV() {
  return 30;
}
