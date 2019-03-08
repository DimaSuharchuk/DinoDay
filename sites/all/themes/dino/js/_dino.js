(function ($) {
    Drupal.behaviors.addCollectionFormRadioClass = {
        attach: function (context) {
            $('.dinosaurs-table img', context).each(function () {
                const rankClass = $(this).data('rank');
                $(this).closest('.form-item-dinosaurs').addClass(rankClass);
            });
        }
    };

    Drupal.behaviors.chooseElements = {
        attach: function (context) {
            // Disable cook button if nothing is selected.
            $('.cook-wrapper input').attr('disabled', true);

            $('.user-consumables-block input[type=checkbox]', context).on('click', function () {
                const target_fieldset = $(this).closest('fieldset');
                $(this).parent().find('img').toggleClass('checked');
                const checkedCount = $('input:checkbox:checked').length;

                // Prevent choose items from other range.
                if (checkedCount > 0) {
                    $(target_fieldset).siblings().find('input:checkbox').attr('disabled', true);
                    $(target_fieldset).siblings().find('img').addClass('muted');
                }
                else {
                    $(target_fieldset).siblings().find('input:checkbox').attr('disabled', false);
                    $(target_fieldset).siblings().find('img').removeClass('muted');
                }

                // Show button if chosen 3 items.
                if (checkedCount === 3) {
                    $('.cook-wrapper').addClass('active');
                    $('.cook-wrapper input').attr('disabled', false);

                    // Click the "cook" button when the image was clicked.
                    $('.cook-wrapper.active').on('click', function () {
                        $('.cook-bait-button').mousedown();
                    });
                } else {
                    $('.cook-wrapper').removeClass('active').unbind();
                    $('.cook-wrapper input').attr('disabled', true);
                }
            });
        }
    };

    Drupal.behaviors.animateFoodReward = {
        attach: function () {
            if ($('#consumables-reward-wrapper').find('img').length) {
                if (window.location.pathname.indexOf('user') === 1) {
                    // Remove consumables reward image on "user edit" page.
                    $('#consumables-reward-wrapper img').remove();
                } else {
                    // On other pages show consumables reward animation.
                    $('#consumables-reward-wrapper img').animate({
                        width: '300px',
                        height: '300px',
                        opacity: 0,
                    }, 3000, function () {
                        $(this).remove();
                    });
                }
            }
        }
    };

    Drupal.behaviors.setBaitButtonDisplay = {
        attach: function (context) {
            if ($('#catch-wrapper img').length) {
                // Remove unnecessary button when bait already installed.
                $('.set-bait').remove();
            } else {
                $('.bait input[type=checkbox]', context).on('click', function () {
                    if ($('input:checkbox:checked').length !== 1) {
                        $('.set-bait', context).addClass('invisible');
                    } else {
                        $('.set-bait', context)
                            .removeClass('invisible')
                            .css({
                                top: $(this).closest('.fieldset-wrapper').offset().top - 204,
                                left: $(this).closest('.fieldset-wrapper').offset().left + 150,
                            })
                            .animate({
                                opacity: 1,
                            }, 500);
                    }
                });
            }
        }
    };

    // Fix strange bug with checked elements after ajax form rebuild from other form.
    Drupal.behaviors.ajaxRebuildFormFix = {
        attach: function (context) {
            $('#user-consumables-block input:checkbox:checked', context).prop('checked', false);
        }
    };
})(jQuery);