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
})(jQuery);