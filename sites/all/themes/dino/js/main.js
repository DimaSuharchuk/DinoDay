(function ($) {
    Drupal.behaviors.chooseElements = {
        attach: function (context) {
            // Disable cook button if nothing is selected.
            $('.cook-wrapper input').attr('disabled', true);

            $('.user-food-block input[type=checkbox]', context).on('click', function () {
                var target_fieldset = $(this).closest('fieldset');
                $(this).parent().find('img').toggleClass('checked');
                var checkedCount = $('input:checkbox:checked').length;

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
                } else {
                    $('.cook-wrapper').removeClass('active');
                    $('.cook-wrapper input').attr('disabled', true);
                }
            });
        }
    };

    Drupal.behaviors.animateFoodReward = {
        attach: function () {
            if ($('#food-reward-wrapper').find('img').length) {
                $('#food-reward-wrapper img').animate({
                    width: '300px',
                    height: '300px',
                    opacity: 0,
                }, 3000, function () {
                    $(this).remove()
                })
            }
        }
    };

    Drupal.behaviors.setBaitButtonDisplay = {
        attach: function (context) {
            if ($('#catch-wrapper img').length) {
                // Remove unnecessary button when bait already installed.
                $('.set-bait').remove();
                // Fix strange bug with checked element after ajax form rebuild from other form.
                $('.bait input:checkbox:checked', context).prop('checked', false);
            } else {
                $('.bait input[type=checkbox]', context).on('click', function () {
                    if ($('input:checkbox:checked').length !== 1) {
                        $('.set-bait').addClass('invisible');
                    } else {
                        $('.set-bait').removeClass('invisible');
                    }
                });
            }
        }
    };
})(jQuery);