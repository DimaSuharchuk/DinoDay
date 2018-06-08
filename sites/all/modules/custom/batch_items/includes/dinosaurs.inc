<?php
/**
 * @file
 * Dinosaurs info for batch.
 */

/**
 * Helper function returns array with all dinosaurs.
 *
 * @return array
 */
function _get_dinosaurs() {
  $dinosaurs = [];

  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/alamozavr.svg',
    'name' => 'Alamosaurus',
    'grade' => 1,
    'food_type' => 'Fruits',
    'favorite_food' => 'Apple',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/amurozavr.svg',
    'name' => 'Amurosaurus',
    'grade' => 1,
    'food_type' => 'Seafood',
    'favorite_food' => 'Fish',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/brahiozavr.svg',
    'name' => 'Brachiosaurus',
    'grade' => 1,
    'food_type' => 'Meat',
    'favorite_food' => 'Bacon',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/cherepozavr.svg',
    'name' => 'Scaullcrouller',
    'grade' => 1,
    'food_type' => 'Fruits',
    'favorite_food' => 'Fig',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/izizavr.svg',
    'name' => 'Easysaurus',
    'grade' => 1,
    'food_type' => 'Seafood',
    'favorite_food' => 'Octopus',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/kusatops.svg',
    'name' => 'Biteops',
    'grade' => 1,
    'food_type' => 'Meat',
    'favorite_food' => 'Chicken',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/mapuzavr.svg',
    'name' => 'Mapusaurus',
    'grade' => 1,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Broccoli',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/mimizavr.svg',
    'name' => 'Mimisaurus',
    'grade' => 1,
    'food_type' => 'Fruits',
    'favorite_food' => 'Pear',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/pamparaptor.svg',
    'name' => 'Pamparaptor',
    'grade' => 1,
    'food_type' => 'Seafood',
    'favorite_food' => 'Salmon',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/pentidrako.svg',
    'name' => 'Pentidraco',
    'grade' => 1,
    'food_type' => 'Fruits',
    'favorite_food' => 'Pineapple',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/plateozavr.svg',
    'name' => 'Plateosaurus',
    'grade' => 1,
    'food_type' => 'Meat',
    'favorite_food' => 'Ham',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tryceratops.svg',
    'name' => 'Triceratops',
    'grade' => 1,
    'food_type' => 'Seafood',
    'favorite_food' => 'Shrimp',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tsaraptor.svg',
    'name' => 'Ciraptor',
    'grade' => 1,
    'food_type' => 'Meat',
    'favorite_food' => 'Steak',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tselur.svg',
    'name' => 'Coelurus',
    'grade' => 1,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Cabbage',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/yamatseratops.svg',
    'name' => 'Yamaceratops',
    'grade' => 1,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Carrot',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  // 2
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/diplodoc.svg',
    'name' => 'Diplodocus',
    'grade' => 2,
    'food_type' => 'Fruits',
    'favorite_food' => 'Apple',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/kapitozavr.svg',
    'name' => 'Lollipopsis',
    'grade' => 2,
    'food_type' => 'Fruits',
    'favorite_food' => 'Fig',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/lokozavr.svg',
    'name' => 'Locosaurus',
    'grade' => 2,
    'food_type' => 'Fruits',
    'favorite_food' => 'Pear',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/minozavr.svg',
    'name' => 'Minosaurus',
    'grade' => 2,
    'food_type' => 'Seafood',
    'favorite_food' => 'Fish',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/multizavr.svg',
    'name' => 'Multisaurus',
    'grade' => 2,
    'food_type' => 'Seafood',
    'favorite_food' => 'Octopus',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/pentatseratops.svg',
    'name' => 'Pentaceratops',
    'grade' => 2,
    'food_type' => 'Meat',
    'favorite_food' => 'Bacon',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/stegozavr.svg',
    'name' => 'Stegosaurus',
    'grade' => 2,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Tomato',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/superzavr.svg',
    'name' => 'Supersaurus',
    'grade' => 2,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Broccoli',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/uranozavr.svg',
    'name' => 'Uranosaurus',
    'grade' => 2,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Cabbage',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/combozavr.svg',
    'name' => 'Combosaurus',
    'grade' => 2,
    'food_type' => 'Meat',
    'favorite_food' => 'Chicken',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  // 3
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/brontozavr.svg',
    'name' => 'Apatosaurus',
    'grade' => 3,
    'food_type' => 'Fruits',
    'favorite_food' => 'Pineapple',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/shypast.svg',
    'name' => 'Spike',
    'grade' => 3,
    'food_type' => 'Seafood',
    'favorite_food' => 'Salmon',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/skalozavr.svg',
    'name' => 'Scolosaurus',
    'grade' => 3,
    'food_type' => 'Vegetables',
    'favorite_food' => 'Carrot',
    'consume' => JURASSIC_CONSUME_HERB,
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/tyranozavr.svg',
    'name' => 'Tyrannosaurus',
    'grade' => 3,
    'food_type' => 'Meat',
    'favorite_food' => 'Ham',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];
  // 4
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/4/nanotyran.svg',
    'name' => 'Nanotyrannus',
    'grade' => 4,
    'food_type' => 'Meat',
    'favorite_food' => 'Steak',
    'consume' => JURASSIC_CONSUME_MEAT,
  ];

  return $dinosaurs;
}
