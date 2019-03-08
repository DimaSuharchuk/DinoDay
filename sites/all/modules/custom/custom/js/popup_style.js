(function ($) {
    // Initialize nanoScroller.
    Drupal.behaviors.nanoScrollerInit = {
        attach: function () {
            $('.nano').nanoScroller();
        }
    };

    Drupal.theme.prototype.customPopupTheme = function () {
        return '<div id="ctools-modal" class="popups-box dino-popup">' +
            '     <div class="ctools-modal-content ctools-modal-dino-popup">' +
            '       <div class="modal-header">' +
            '         <span class="popups-close">' +
            '           <a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '</a>' +
            '         </span>' +
            '         <span id="modal-title" class="modal-title"></span>' +
            '       </div>' +
            '       <div class="modal-msg"></div>' +
            '       <div class="modal-scroll content-wrapper">' +
            '         <div class="nano">' +
            '           <div id="modal-content" class="modal-content popup-body nano-content"></div>' +
            '         </div>' +
            '       </div>' +
            '     </div>' +
            '   </div>';
    };

    Drupal.behaviors.addModalCloseIcon = {
        attach: function () {
            $('#modalBackdrop').html('<i class="material-icons popup-close">close</i>');
        }
    };

    Drupal.behaviors.alignPopup = {
        attach: function () {
            if ($('#modalContent').length) {
                // Prevent ugly page background scroll.
                $(window).scrollTop(0);
                $('body .page').css('position', 'fixed');

                modalContentResize();
                $('#modalBackdrop').css({height: '100%', width: '100%'});
            }
        }
    };

    Drupal.behaviors.closePopups = {
        attach: function () {
            $('#modalBackdrop, .close').bind('click', function () {
                modalContentClose();
                $('body .page').css('position', 'relative');
            });
        }
    };
})(jQuery);