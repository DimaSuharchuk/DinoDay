(function ($) {
    Drupal.behaviors.timer = {
        attach: function (context) {
            const timer = $('.active-timer', context).text().split(':');
            let min = Number.parseInt(timer[0]);
            let sec = Number.parseInt(timer[1]);
            if (min || sec) {
                const interval = setInterval(function () {
                    sec--;

                    if (sec < 0) {
                        sec = 59;
                        min--;

                    }

                    $('.active-timer', context).text(numberToTimeFormat(min) + ':' + numberToTimeFormat(sec));

                    if (min <= 0 && sec <= 0) {
                        clearInterval(interval);
                        window.location.reload()
                    }
                }, 1000);
            }
        }
    };

    function numberToTimeFormat(n) {
        return n < 10 ? '0' + n : n;
    }
})(jQuery);