<div class="columns small-3">
    <div class="dinosaur-rank rank-<?php print $grade; ?>">
        <span><?php print $grade; ?></span>
    </div>
</div>
<div class="dinosaur-attributes columns small-9">
    <h2 class="dinosaur-name"><?php print t($name); ?></h2>
    <div>
      <?php print t('Food type'); ?>:
        <strong><?php print t($food_type); ?></strong>
    </div>
    <div>
      <?php print t('Favorite food'); ?>:
        <strong><?php print t($favorite_food); ?></strong>
    </div>
</div>

<div class="dinosaur-bars columns">
    <div>
      <?php print t('Age'); ?>: <strong><?php print $age; ?></strong>
    </div>
    <div>
      <?php print t('Health'); ?>:
        <strong><?php print $health; ?>%</strong>
    </div>
    <div>
      <?php print t('Satiety'); ?>:
        <strong><?php print $satiety; ?>%</strong>
    </div>
</div>

<div class="dinosaur-mood columns small-3">

</div>
<div class="dinosaur-picture-wrapper columns small-9">
    <img src="<?php print $picture_path; ?>" alt=""/>
</div>
