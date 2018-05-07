(function ($) {
    Drupal.behaviors.chooseElements = {
        attach: function (context) {
            // Disable cook button if nothing is selected.
            $('.cook-wrapper input').attr('disabled', true);

            $('.user-food-block input[type=checkbox]', context).on('click', function () {
                $(this).parent().find('img').toggleClass('checked');
                var checkedCount = $('input:checkbox:checked').length;
                if (checkedCount === 3) {
                    $('.cook-wrapper').addClass('active');
                    $('.cook-wrapper input').attr('disabled', false);
                } else {
                    $('.cook-wrapper').removeClass('active');
                    $('.cook-wrapper input').attr('disabled', true);
                }
            });
        }
    }
})(jQuery);