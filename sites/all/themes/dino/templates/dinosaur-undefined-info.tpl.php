<div id="dinosaur-info">
    <div class="dinosaur-picture-wrapper columns medium-6">
        <img src="<?php print $picture_path; ?>" class="no-rank"/>
    </div>
    <div class="dinosaur-main-info columns medium-6">
        <h2 class="dinosaur-name"><?php print t('Unknown dinosaur'); ?></h2>
        <p><?php print t('Rank'); ?>: <strong><?php print $grade; ?></strong></p>
    </div>
</div>