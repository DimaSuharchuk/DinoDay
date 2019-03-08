<?php

/**
 * @file
 * Collect all constants for DinoDay project.
 */

/**
 * Defines site main theme name.
 */
define('DINO_THEME_NAME', 'dino');
/**
 * Defines path to DinoDay theme.
 */
define('DINO_THEME_PATH', 'sites/all/themes/' . DINO_THEME_NAME);
/**
 * Defines path to directory with dinosaurs pictures.
 */
define('DINO_PICTURE_DIR', DINO_THEME_PATH . '/images/dino');
/**
 * Defines path to directory with food pictures.
 */
define('FOOD_PICTURE_DIR', DINO_THEME_PATH . '/images/food');
/**
 * Defines path to directory with jurassic dinosaurs pictures.
 */
define('JURASSIC_PICTURE_DIR', DINO_THEME_PATH . '/images/jurassic');

/**
 * Defines maximum quiz energy value.
 */
define('QUIZ_ENERGY_MAX', 10);

/**
 * Defines dinosaurs lifetime in seconds.
 */
define('DINOSAUR_RANK_1_LIFETIME', 259200); // 3 days
define('DINOSAUR_RANK_2_LIFETIME', 518400); // 6 days
define('DINOSAUR_RANK_3_LIFETIME', 1036800); // 12 days
define('DINOSAUR_RANK_4_LIFETIME', 2073600); // 24 days

/**
 * Defines jurassic dinosaurs feeding.
 */
define('JURASSIC_CONSUME_MEAT', 'carnivore'); // Meat
define('JURASSIC_CONSUME_HERB', 'herbivore'); // Herb, plants
define('JURASSIC_CONSUME_ALL', 'omnivore'); // Meat, herb, plants
