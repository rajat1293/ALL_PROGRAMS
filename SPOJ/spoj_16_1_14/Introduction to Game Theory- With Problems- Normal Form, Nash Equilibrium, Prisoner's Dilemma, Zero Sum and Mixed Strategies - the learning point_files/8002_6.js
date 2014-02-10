var showPopup = Math.floor(Math.random()*10)%2;
var _amzn_utils = {
    insertStyleSheet: function(stylesheetId, path, marketPlace) {
        if (!document.getElementById(stylesheetId)) {
            var objHead = document.getElementsByTagName('head');
            if (objHead[0]) {
                var stylesheetObj;
                if (document.createElementNS && objHead[0].tagName == 'head') {
                    stylesheetObj = document.createElementNS('http://www.w3.org/1999/xhtml', 'link');
                } else {
                    stylesheetObj = document.createElement('link');
                }
                stylesheetObj.id = stylesheetId;
                stylesheetObj.rel = 'stylesheet';
                stylesheetObj.href = this.amznMediaserverURL(marketPlace) + path;
                stylesheetObj.type = 'text/css';
                objHead[0].appendChild(stylesheetObj);
            }
        }
    },

    objHasOwnProperty: function(obj, property){
        return Object.prototype.hasOwnProperty ? obj.hasOwnProperty(property) : typeof obj[property] != "function";
    },

    insertAfter: function(node, ref, force) {
        var pn = ref.parentNode;
        if(ref == pn.lastChild){
            if((!force)&&(node === ref)){
                return false;
            }
            pn.appendChild(node);
        } else {
            return this.insertBefore(node, ref.nextSibling, force);
        }
        return true;
    },

    insertBefore: function(node, ref, force) {
        if (!force && (node === ref || node.nextSibling === ref)){
            return false;
        }
        var parent = ref.parentNode;
        parent.insertBefore(node, ref);
        return true;
    },

    getById: function(id, parentNode) {
        if (this.isAppleWebKit()) {
            var result = null;
            var childNodes = parentNode.childNodes;
            for (var i = 0; i < childNodes.length; i++) {
                if (result != null) return result;
                var childNode = childNodes[i];
                if (childNode && childNode.childNodes && childNode.childNodes.length > 0) {
                    var temp = this.getById(id, childNode);
                    if (temp != null) {
                        result = temp;
                    }
                }
                if (childNode && childNode.id == id) {
                    result = childNode;
                }
            }

            return result;
        } else {
            var result = null;
            var childNodes = parentNode.childNodes;
            for (var i in childNodes) {
                if (result != null) return result;
                var childNode = childNodes[i];
                if (childNode && childNode.childNodes && childNode.childNodes.length > 0) {
                    var temp = this.getById(id, childNode);
                    if (temp != null) {
                        result = temp;
                    }
                }
                if (childNode && childNode.id == id) {
                    result = childNode;
                }
            }
            return result;
        }
    },

    byId: function(id, doc) {
        if ((id) && ((typeof id == 'string') || (id instanceof String))) {
            doc = document;
            var ele = doc.getElementById(id);
            if (ele && (ele.id != id) && doc.all) {
                ele = null;
                var eles = doc.all[id];
                if (eles) {
                    if (eles.length) {
                        for (var i = 0; i < eles.length; i++) {
                            if (eles[i].id == id) {
                                ele = eles[i];
                                break;
                            }
                        }
                    } else {
                        ele = eles;
                    }
                }
            }
            return ele;
        }
        return id;
    },

    replaceAll: function( str, searchValue, replaceValue ) {
        if(str==null){
            return str;
        }
        var idx = str.indexOf( searchValue );

        while ( idx > -1 ) {
            str = str.replace( searchValue, replaceValue );
            idx = str.indexOf( searchValue );
        }
        return str;
    },

    msie: '',
    amzn_isMSIE: function() {
        if (this.msie == '') {
            this.msie = navigator.userAgent.toLowerCase().indexOf('msie') > 0;
        }
        return this.msie;
    },

    msie_6: '',
    amzn_isMSIE_6: function() {
        if (this.msie_6 == '') {
            this.msie_6 = /MSIE (5\.5|6\.)/.test(navigator.userAgent);
        }
        return this.msie_6;
    },

    firefox_1_5: '',
    isFirefox_1_5: function() {
        if (this.firefox_1_5 == '') {
            this.firefox_1_5 = navigator.userAgent.toLowerCase().indexOf('firefox/1.5') > 0;
        }
        return this.firefox_1_5;
    },
    
    firefox_2_0: '',
    isFirefox_2_0: function() {
        if (this.firefox_2_0 == '') {
            this.firefox_2_0 = navigator.userAgent.toLowerCase().indexOf('firefox/2.0') > 0;
        }
        return this.firefox_2_0;
    },
    
    firefox: '',
    isFirefox: function() {
        if (this.firefox == '') {
            this.firefox = navigator.userAgent.toLowerCase().indexOf('firefox') > 0;
        }
        return this.firefox;
    },

    safari: '',
    isAppleWebKit: function() {
        if (this.safari == '') {
            this.safari = navigator.userAgent.toLowerCase().indexOf('applewebkit') > 0;
        }
        return this.safari;
    },

    $: function(id) {
        return this.byId(id, document);
    },

    validateParams: function(req_params) {
        var isParamValid = true;
        for (var param in req_params) {
            if (_amzn_utils.objHasOwnProperty(req_params,param)) {
                if (typeof req_params[param] == 'undefined') {
                    isParamValid = false;
                    return;
                }
            }
        }
        return isParamValid;
    },

    clone: function(myObj) {
        if (myObj == null) return myObj;
        var objectClone = new myObj.constructor();
        for (var property in myObj) {
            if (_amzn_utils.objHasOwnProperty(myObj, property)) {
                if (typeof myObj[property] == 'object') {
                    objectClone[property] = this.clone(myObj[property]);
                } else {
                    objectClone[property] = myObj[property];
                }
            }
        }
        return objectClone;
    },

    runPNGTransparencyHackForBkgdImage: function(element) {
        if (/MSIE (5\.5|6\.)/.test(navigator.userAgent) && element) {
            var bgImg = element.currentStyle.backgroundImage || element.style.backgroundImage;
            if (bgImg) {
                var runIELinkHack = false;
                if(bgImg.match(/^url[("']+(.*\.png)[)"']+$/i)) {
                    var imageURL = RegExp.$1;
                    if (imageURL && imageURL.indexOf('_tpng.png') > 0) {
                        if (element.currentStyle.width == 'auto' && element.currentStyle.height == 'auto') {
                            element.style.width = element.offsetWidth + 'px';
                        }
                        element.style.backgroundImage = 'none';
                        element.style.filter = 'progid:DXImageTransform.Microsoft.AlphaImageLoader' + '(src=\'' + imageURL + '\',sizingMethod=\'scale\')'
                    }
                    runIELinkHack = true;
                } else if(bgImg == 'none') {
                    runIELinkHack = true;
                }
                if(runIELinkHack) {
                    // IE link fix.
                    for (var n = 0; n < element.childNodes.length; n++) {
                        if (element.childNodes[n].style) {
                            element.childNodes[n].style.position = 'relative';
                        }
                    }
                }
            }
        }
    },

    runPNGTransparencyHack: function(element, marketPlace) {
        if (typeof marketPlace == 'undefined') {
            marketPlace = 'US';
        }
        if (/MSIE (5\.5|6\.)/.test(navigator.userAgent) && element) {
            if (window.ActiveXObject) {
                var inputs = element.getElementsByTagName('input');
                for (var i = 0; i < inputs.length; ++i) {
                    if (inputs[i].src.indexOf('_tpng.png') > 0) {
                        var src = inputs[i].src;
                        inputs[i].src = this.imageDirectory(marketPlace) + '/transparent-pixel.gif';
                        inputs[i].style.filter = 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src=\'' + src + '\',sizingMethod=\'scale\')';
                    }
                }

                var images = element.getElementsByTagName('img');
                for (var i = 0; i < images.length; ++i) {
                    if (images[i].src.indexOf('_tpng.png') > 0) {
                        var src = images[i].src;
                        images[i].src = this.imageDirectory(marketPlace) + '/transparent-pixel.gif';
                        images[i].style.filter = 'progid:DXImageTransform.Microsoft.AlphaImageLoader(src=\'' + src + '\',sizingMethod=\'scale\')';
                    }
                }
            }
        }
    },

    stripTags: function(str) {
        if (str == null) { return null; }
        return str.replace(/<\/?[^>]+>/gi, '');
    },

    unescapeHTML: function(text) {
        var div = document.createElement('div');
        div.innerHTML = this.stripTags(text);
        return div.childNodes[0] ? div.childNodes[0].nodeValue : '';
    },

    escapeHTML: function(text) {
        if (typeof text == 'string') {
            var div = document.createElement('div');
            var node = document.createTextNode(text);
            div.appendChild(node);
            return div.innerHTML;
        } else if (typeof text == 'array') {
            for (var i = 0; i < text.length; i++) {
                text[i] = this.escapeHTML(text[i]);
            }
        } else if (typeof text == 'object') {
            for (var i in text) {
                if (_amzn_utils.objHasOwnProperty(text, i)) {
                    text[i] = this.escapeHTML(text[i]);
                }
            }
        }
        return text;
    },

    getRatingImage: function(rating, marketPlace) {
        if (!rating) return '';
        var reviewImg;
        var review = rating.split('.');
        if (review && review.length == 2) {
            var reviewImgName = review[0] + review[1];
            reviewImg = '<img style=\'height:11px; width:56px;border: none;margin:0;\' src=\'' + _amzn_utils.imageDirectory(marketPlace) + '/star' + reviewImgName + '_tpng.png\'/>';
        }
        return reviewImg;
    },

    numberOfOccurencesOfSubstr: function(str, substring) {
        var count = 0;
        var pos = str.indexOf(substring);
        while (pos != -1) {
            count++;
            pos = str.indexOf(str, pos + substring.length);
        }
        return count;
    },

    _amzn_popup_onshow_callback: function() {
        _amzn_utils.runPNGTransparencyHack(_amzn_utils.$('amzn_popup_div'));
    },

    _amzn_popup_callback_helper: function() {
        _amzn_popup.onshow_callback =  _amzn_utils._amzn_popup_onshow_callback;
        _amzn_popup.onhide_callback = _amzn_utils._amzn_popup_onhide_callback;
    },

    _amzn_popup_onhide_callback: function() {
//        _amzn_popup.onshow_callback = null;
        /*Had to be removed because of http://carbon/secure/dotproject/index.php?m=tasks&a=view&task_id=1010*/
        _amzn_popup.onhide_callback = null;
    },

    
    getTile: function(result, self, comment, numberOfTitleLines) {
        var innerTileWidth = Math.floor((self.innerWidth - 6 * self.cols) / self.cols);
        var res = '<div class=\'wdgt_tl_pad\'>'
                + '<div class=\'wdgt_tl\' style=\'height:' + self.height + 'px;width:' + innerTileWidth + 'px\'>';

        if (typeof result == 'string' && result == 'INVALID') {
            res += '<a target=\'_blank\' href=\'' + _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace) + '\'><img style=\'width:40px;height:54px;border:none\' src=\'' + _amzn_utils.imageDirectory(self.marketPlace) + '/itemNoLongerAvailable-40px.gif\'></a>';
            res += '</div>';
            res += '</div>';
            return res;
        }

        var popUpTile = escape(self.createPopupTile(result));
        var imageElement = '';
        var titleElement = '';
        var subTitleElement = '';
        var priceElement = '';
        var reviewElement = '';
        var commentElement = '';

        var detailPageURL = _amzn_utils.getURL(result['DetailPageURL'], self);
        var extraPadding = 10;
        var titleWidth = innerTileWidth - 50; // reducing the padding for the title.
        var subTitleWidth = innerTileWidth - 50;

        var imgHeight = 0;
        var imageElementLine1 = '';
		var isShowingRating = self.show_review && result['Rating'];
		var isShowingPrice = self.show_price && result['Price'];
		if (self.show_image) {
            var imgURL = result['ThumbImageUrl'];
            var imgWidth = result['ThumbImageWidth'];
            imgHeight = result['ThumbImageHeight'];

            if (!imgURL || imgURL == '') {
                imgURL = _amzn_utils.imageDirectory(self.marketPlace) + '/noImageAvailable-40px.gif';
            }
            if (!imgWidth || imgWidth == '') {
                imgWidth = 40;
            }
            if (!imgHeight || imgHeight == '') {
                imgHeight = 44;
            }

            if (imgWidth > 40) {
                imgWidth = 40;
                imgHeight = Math.floor(40 * result['ThumbImageHeight'] / result['ThumbImageWidth']);
            }

            if (imgHeight > 60) {
                imgHeight = 60;
                imgWidth = Math.floor(60 * result['ThumbImageWidth'] / result['ThumbImageHeight']);
            }
            
            if(!isShowingRating && self.isIAB && self.wdgt_height==250){
            	if (imgHeight > 55) {
	                imgHeight = 55;
                	imgWidth = Math.floor(55 * result['ThumbImageWidth'] / result['ThumbImageHeight']);
            	}
            }

            imageElementLine1 = '<div class=\'asin_img\' ';
	
	    //If the widget is being viewed on WC then do no a/b of popover
            if(typeof getWidgetParams != 'undefined'){
                showPopup = 1;
            }

            if (self.isWidgetSource && (self.templateId == '8001' || self.templateId == '8002')) {
                    imageElement = '><a style=\'float:left;' + self.style_tile_asin_a() + '\' target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN']  + '");\' onmouseout=\'_amzn_popup.hide()\' href=\'' + detailPageURL + '\'>'
                            + '<img src=\'' + imgURL + '\' width=\'' + imgWidth
                            + '\' height=\'' + imgHeight + '\' style=\'border: none;margin:0;' + self.style_tile_asin_img() + '\' /></a></div>';
           } else {
                  if(self.templateId == '8002'&&showPopup=='0'){
                      imageElement = '><a style=\'float:left;' + self.style_tile_asin_a() + '\' target=\'_blank\' onmouseover=\'\' onmouseout=\'_amzn_popup.hide()\' href=\'' + detailPageURL + '\'>'
                                                         + '<img src=\'' + imgURL + '\' width=\'' + imgWidth
                                                         + '\' height=\'' + imgHeight + '\' style=\'border: none;margin:0;' + self.style_tile_asin_img() + '\' /></a></div>';
                  }else{
                      imageElement = '><a style=\'float:left;' + self.style_tile_asin_a() + '\' target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] +'");\' onmouseout=\'_amzn_popup.hide()\' href=\'' + detailPageURL + '\'>'
                                    + '<img src=\'' + imgURL + '\' width=\'' + imgWidth
                                    + '\' height=\'' + imgHeight + '\' style=\'border: none;margin:0;' + self.style_tile_asin_img() + '\' /></a></div>';
                  }
          }
		           

            // 6px is the image padding
            if (innerTileWidth > 150 || self.isIAB) {
                titleWidth = innerTileWidth - 50;
            }
            if(self.isIAB) {
                titleWidth -= 5;
            }
            subTitleWidth = innerTileWidth - 55;
        } else {
            titleWidth = innerTileWidth - extraPadding;
            subTitleWidth = innerTileWidth - extraPadding - 5;
        }
        var hasComment = false;
        if(comment){
	        for(var k = 0; k < comment.length;k++){
	        	var commentStr = comment[k];
	        	if(!(typeof commentStr == 'undefined' || commentStr == null || commentStr == '' || commentStr.length == 0)){
	        		hasComment = true;
	        		break;
	        	}
	        }
        }
        if (hasComment) {
            var numOfLinesOfComment = 2;
			// 60px is the max height
            // and we need 15px for each extra line of comment
            if (self.show_image) {
                var imageOuterDivHeight = 15; // subtitle
                if (innerTileWidth >= 150) {
                    imageOuterDivHeight += 15; //title
                    
                }
                if (isShowingRating) {
                    imageOuterDivHeight += 15; // rating
                }
                if (isShowingPrice) {
                    imageOuterDivHeight += 15; //price
                }

                imageOuterDivHeight = Math.max(imgHeight, imageOuterDivHeight);
                imageElementLine1 += 'style=\'height:' + imageOuterDivHeight + 'px;\'';
                if(self.isIAB && typeof(numberOfTitleLines) != 'undefined' && numberOfTitleLines > 1){
                 	imageOuterDivHeight += numberOfTitleLines*14; //title
                }
                numOfLinesOfComment += Math.floor((60 - imageOuterDivHeight)/12);
                if(self.isIAB){
                	numOfLinesOfComment  = 2;
					if(self.wdgt_height == 280){
		            	numOfLinesOfComment = 1;
		            	if(numberOfTitleLines > 1){
		            		var tmpNumberOfTitleLines = 1;
			            	if(self.show_image && !isShowingPrice){
			            		tmpNumberOfTitleLines = 2;	
			            	}
	            	                if(self.show_image && !isShowingRating && tmpNumberOfTitleLines < numberOfTitleLines){
			            		
			            		tmpNumberOfTitleLines++;	
			            	}
			            	numberOfTitleLines = tmpNumberOfTitleLines;
		            	}
					}
	            	if(self.wdgt_height == 250){
	            		numOfLinesOfComment = 1;
	            		if(isShowingRating){
	                		comment = "";
	            		}else{
					if(numberOfTitleLines > 1){
						numberOfTitleLines--;
					}
				}
	            	}
	            	if(self.wdgt_height == 150){
        				comment = "";
			        }
                }
            }
        
	 		if ( self.isWidgetSource && (self.templateId == '8001' || self.templateId == '8002')) {
                commentElement = '<div onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] + '");\' onmouseout=\'_amzn_popup.hide()\' class=\'asin_cmnt\' style=\'cursor:pointer;width:' + innerTileWidth + 'px;' + self.style_tile_comment() + '\'>' +
                                 self.trimMultiLineComments(comment, '10', innerTileWidth - 6, numOfLinesOfComment) + '</div>';
            } else {
                if(self.templateId == '8002'&&showPopup=='0'){
                    commentElement = '<div onmouseover=\'\' onmouseout=\'_amzn_popup.hide()\' class=\'asin_cmnt\' style=\'cursor:pointer;width:' + innerTileWidth + 'px;' + self.style_tile_comment() + '\'>' +
                                           self.trimMultiLineComments(comment, '10', innerTileWidth - 6, numOfLinesOfComment) + '</div>';
                }else{
                    commentElement = '<div onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] +'");\' onmouseout=\'_amzn_popup.hide()\' class=\'asin_cmnt\' style=\'cursor:pointer;width:' + innerTileWidth + 'px;' + self.style_tile_comment() + '\'>' +
                                        self.trimMultiLineComments(comment, '10', innerTileWidth - 6, numOfLinesOfComment) + '</div>';
                }
            }
        }
		var leftPadding = "";
		var titleText = "";
		if(self.isIAB && self.show_image){
        		leftPadding= "padding-left:" + (imgWidth+2) + "px;";
        }
		if(self.isIAB && typeof(numberOfTitleLines) != 'undefined'){
			titleText = self.trimCharsByWidth(this.escapeHTML(result['Title']), '10bold', titleWidth, numberOfTitleLines);
		}else{
			titleText = self.trimCharsByWidth(this.escapeHTML(result['Title']), '10bold', titleWidth);
		}
       if (self.isWidgetSource && (self.templateId == '8001' || self.templateId == '8002')) {
       		
            titleElement = '<div style=\'' + self.style_tile_h1() + ';' + leftPadding + '\' class=\'asin_h1\'><a target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] + '");\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + self.style_tile_h1_a() + '\' href=\'' + detailPageURL + '\'>' + titleText + '</a></div>';
        } else {
            if(self.templateId == '8002'&&showPopup=='0'){
                titleElement = '<div style=\'' + self.style_tile_h1() + ';' + leftPadding + '\' class=\'asin_h1\'><a target=\'_blank\' onmouseover=\'\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + self.style_tile_h1_a() + '\' href=\'' + detailPageURL + '\'>' + titleText + '</a></div>';
            }else{
                titleElement = '<div style=\'' + self.style_tile_h1() + ';' + leftPadding + '\' class=\'asin_h1\'><a target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] +'");\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + self.style_tile_h1_a() + '\' href=\'' + detailPageURL + '\'>' + titleText + '</a></div>';
            }
        }
                                                                                                                                                             
        if (self.isWidgetSource && (self.templateId == '8001' || self.templateId == '8002')) {
            subTitleElement = '<div style=\'' + self.style_tile_h2() + ';' + leftPadding + '\' class=\'asin_h2\'><a target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] +'");\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + '\' href=\'' + detailPageURL + '\'>' + self.trimCharsByWidth(this.escapeHTML(result['Subtitle']), '9', subTitleWidth) + '</a></div>';
        } else {
            if(self.templateId == '8002'&&showPopup=='0'){
                subTitleElement = '<div style=\'' + self.style_tile_h2() + ';' + leftPadding + '\' class=\'asin_h2\'><a target=\'_blank\' onmouseover=\'\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + '\' href=\'' + detailPageURL + '\'>' + self.trimCharsByWidth(this.escapeHTML(result['Subtitle']), '9', subTitleWidth) + '</a></div>';
            }else{
                subTitleElement = '<div style=\'' + self.style_tile_h2() + ';' + leftPadding + '\' class=\'asin_h2\'><a target=\'_blank\' onmouseover=\'_amzn_utils._amzn_popup_callback_helper();_a=this; _amzn_popup.showpreview("' + popUpTile + '", _a, event, 500,"' + self.tag + '","' + self.linkCode  + '", "' + self.marketPlace + '", "' + result['ASIN'] +'");\' onmouseout=\'_amzn_popup.hide()\' style=\'' + self.style_tile_a() + '\' href=\'' + detailPageURL + '\'>' + self.trimCharsByWidth(this.escapeHTML(result['Subtitle']), '9', subTitleWidth) + '</a></div>';
            }
        }
        if (isShowingPrice) {
        	priceElement = '<div  style=\'' + self.style_tile_price() + ';' + leftPadding + ';\' class=\'asin_price\'>' + result['Price'] + '</div>';
        }
        if (isShowingRating) {
         var reviewurl = _amzn_utils.getString(_amzn_utils.AmazonComLink, self.marketPlace) + 'product-reviews/' + result['ASIN']+ '?';
    reviewurl =  _amzn_utils.getURL(reviewurl, self);

                var productReviewURL = '<a target="_blank" href="' + reviewurl + '">'+ self.getReviewImage(result['Rating']) + '</a>' ;
                    reviewElement = '<div style="' + self.style_tile_review() + ';' + leftPadding + '" class="asin_review">' + productReviewURL  + '</div>';

        }
	imageElement = imageElementLine1 + imageElement;
        if (innerTileWidth < 150 && !self.isIAB) {
            res += titleElement;
            res += imageElement;
        } else {
            res += imageElement;
            res += titleElement;
        }
        res += subTitleElement;
        res += priceElement;
        res += reviewElement;
        if (comment) {
            res += commentElement;
        }

        res += '</div>';
        res += '</div>';
        return res;
    },

    pageNumberDiv: function(pageNumber, isCurrentPage, self, displayPageNumber) {
        if (typeof displayPageNumber == 'undefined') {
            displayPageNumber = pageNumber;
        }

        if (isCurrentPage) {
            return '<strong style=\'' + self.style_pgn_strong() + '\'>' + displayPageNumber + '</strong>';
        } else {
            if(!window.nextCallBack){
                window.nextCallBack = new Object();
            }
            if (!window.nextCallBack[self.marketPlace]) {
                window.nextCallBack[self.marketPlace] = new Object();
            }
            if (!window.nextCallBack[self.marketPlace][self.templateId]) {
                window.nextCallBack[self.marketPlace][self.templateId] = new Object();
            }
            if(!window.nextCallBack[self.marketPlace][self.templateId][self.instanceId]) {
                window.nextCallBack[self.marketPlace][self.templateId][self.instanceId] = new Object();
            }
            window.nextCallBack[self.marketPlace][self.templateId][self.instanceId]['showpage'] = self.showpage;
            return '<a style=\'cursor:pointer;' + self.style_pgn_a() + '\' onclick=\'javascript:window.nextCallBack["' + self.marketPlace + '"][' + self.templateId + '][' + self.instanceId + '].showpage(' + pageNumber + ',' + self.instanceId + ',' + self.templateId + ',"' + self.marketPlace + '");\'>' + displayPageNumber + '</a>';
        }
    },

    calcContrastColor: function(colorInHex) {
        function f(c,n) {
            return parseInt(c.substr(n,2),16);
        }
        var av = (f(colorInHex, 1) + f(colorInHex, 3) + f(colorInHex, 5)) / 3;
        av += (av >= 100)?-100:100;
        return 'rgb(' + av + ',' + av + ',' + av + ')';
    },
    getDigitalCategory:function(category, self) {
	if(category == "Book"){
		return this.getString(this.Kindle, self.marketPlace);
	}else if(category == "Music"){
		return this.getString(this.MP3, self.marketPlace);
	}else if(category == "DVD"){
		return this.getString(this.Unbox, self.marketPlace);
	}
    },		
    createPopupTile: function(result, self, comment) {
        var innerTileWidth = 335;
        var imgURL = result['ThumbImageUrl'];
        var maxImgWidth = 64;
        var maxImgHeight = 97;
        var imgWidth = result['ThumbImageWidth'];
        var imgHeight = result['ThumbImageHeight'];
        var asin_img_style_str = '';
        if (!imgURL || imgURL == '') {
            imgURL = _amzn_utils.imageDirectory(self.marketPlace) + '/noImageAvailable-90px.gif';
            asin_img_style_str= "width:90px;";
            imgWidth = "90";
        }else{
            if(!imgWidth || imgWidth == '' || !imgHeight || imgHeight == ''){
                var largeImgUrl =  result['LargeImageUrl'];
                if(largeImgUrl && largeImgUrl != ''){
                        imgURL=_amzn_utils.getImageURLForDimension(largeImgUrl,imgHeight,imgWidth);
                }
                imgWidth = null;
                imgHeight = null;
            }else{
                if (imgWidth > maxImgWidth || imgHeight >maxImgHeight) {
                        var largeImgUrl =  result['LargeImageUrl'];
                        if(largeImgUrl && largeImgUrl != ''){
                        //We need to get trimmed image.
                                if(imgWidth > maxImgWidth){
                                        imgWidth = maxImgWidth;
                                        imgHeight = Math.ceil(maxImgWidth * result['ThumbImageHeight'] / result['ThumbImageWidth']) + 2;
                                }
                                if( imgHeight >maxImgHeight){
                                        imgHeight = maxImgHeight;
                                        imgWidth = Math.ceil(maxImgHeight * imgWidth / result['ThumbImageHeight']) + 2;
                                }
                                imgURL=_amzn_utils.getImageURLForDimension(largeImgUrl,imgHeight,imgWidth);
                        }
                }
                asin_img_style_str= "width:" + imgWidth + "px;";
            }
            if(imgWidth == null){
                imgWidth = "65";
            }
        }
	var review = '';

        var reviewurl = _amzn_utils.getString(_amzn_utils.AmazonComLink,self.marketPlace)+ 'product-reviews/' +     result['ASIN']+ '?';
        reviewurl =  _amzn_utils.getURL(reviewurl, self);
                        
         var productReviewURL = '<a  target="_blank" href="' + reviewurl + '">'+ self.                          getReviewImage(result['Rating']) +'(' + result['TotalReviews']+  this.getString(this.CustomerReviews, self.marketPlace) + ')' +'</a>' ;
        if(result['Rating']) {
        review = '<div class="asin_review">' + productReviewURL + '</div>';
        }else{
            review = '<div valign=top class=\'asin_review_empty\'></div>';
        }
        var buyPrice = '';
        var addToCart = false;
        if (result['Price']) {
            buyPrice = result['Price'];
        }else{
                 buyPrice = "";
        }
        if(buyPrice == ''){
//          buyPrice = this.getString(this.Now, self.marketPlace);
            addToCart = false;
        }
        var buyButtonStr = this.getString(this.Buy, self.marketPlace);
        var downloadPrice = '';
        var hasDigital = false;
        var digitalCategory='';
        var isDigital = false;
        if(result['isDigital'] == "true"){
                if(self.marketPlace=="US" && (result["category"] == "Movie"||result["category"] == "DVD"||result["category"] == "" || result["category"] == "TV Series Video on Demand" || result["category"] == "TV Series Episode Video on Demand")){
		        buyButtonStr=this.getString(this.WatchNow,self.marketPlace);
		}else{
        		buyButtonStr=this.getString(this.Download,self.marketPlace);
		}
                isDigital = true;
                addToCart = false;
        }
                                                                                                                                                             
        if (!isDigital && result['DigitalAsinPrice']) {
	    hasDigital = true;
            downloadPrice = result['DigitalAsinPrice'];
            if(!downloadPrice || downloadPrice == ''){
	    	hasDigital = false;
                isDigital = false;
            }else{
                hasDigital = true;
                buyButtonStr+=this.getString(result['category'], self.marketPlace);//DVD/Video, CD, Book
                digitalCategory=_amzn_utils.getDigitalCategory(result['category'], self);   // Unbox, Kindle, MP3
            }
        }
        var commentElement = '';
        if (comment) {
            commentElement = '<div class=\'asin_cmnt\' style="width:317px";>' + comment + '</div>';
        }
 var hAndW0=_amzn_utils.getTextHeightAndWidth(buyButtonStr, "100% Verdana, Arial, Helvetica, sans-serif","10", true, "", self);
        var hAndW1=_amzn_utils.getTextHeightAndWidth(buyPrice, "100% Verdana, Arial, Helvetica, sans-serif","10", false, "", self);
        var buy_button_width = hAndW0[1]+hAndW1[1]+21;
        if(hasDigital){
                var hAndW2=_amzn_utils.getTextHeightAndWidth("-or-", "100% Verdana, Arial, Helvetica, sans-serif","10", false, "", self);
                hAndW0=_amzn_utils.getTextHeightAndWidth(this.getString(this.Download, self.marketPlace), "100% Verdana, Arial, Helvetica, sans-serif","10", true, "", self);
                hAndW1=_amzn_utils.getTextHeightAndWidth(downloadPrice, "100% Verdana, Arial, Helvetica, sans-serif","10", false, "", self);
        }
        var dnld_button_width=hAndW0[1]+hAndW1[1]+21;
        /*available_space-dnld_button_width+buy_button_width+hAndW2[1]+4= padding between text..
        */
        var titleWidth = 232;
        var totalWidth = parseInt(imgWidth) + 12;
        var detailWidth = 250;
        if(hasDigital){
                if(dnld_button_width+buy_button_width+5+hAndW2[1] > 250){
                        detailWidth =dnld_button_width+buy_button_width+5+hAndW2[1];
			titleWidth = dnld_button_width+buy_button_width + 5 - 18 + hAndW2[1];
                        totalWidth += detailWidth;
                                                                                                                                                             
                }else{
                        totalWidth+=250;
                                                                                                                                                             
                }
        }else{
                totalWidth += detailWidth;
        }
        var trimmedTitle= _amzn_utils.trimTextBlock(this.escapeHTML(result['Title']), "11bold",titleWidth  , 2, false, self);
        var trimmedSubTitle= _amzn_utils.trimTextBlock(this.escapeHTML(result['Subtitle']), "10",titleWidth  , 2, false, self);
        if(_amzn_utils.amzn_isMSIE()){
                titleWidth=titleWidth+4;
        }
       
        var retObj=  '<div id=\'wdgt_pop_tl\' class=\'wdgt_pop_tl\' style="background:white;">'
                + '<img onclick=\'_amzn_popup.hideNow()\' style=\'top:0px;display:block;right:0px;position:absolute;border:none;margin:0;float:right;cursor:pointer;padding:0;\' src=\'' + _amzn_utils.imageDirectory(self.marketPlace) + '/close-fly-over-new.gif' + '\' hspace=0 />'
                + '<table cellspacing="0" cellpadding="0" style="border:5px solid #cccccc;width:' +totalWidth + 'px"><tr><td><table valign=top align=left cellspacing=0 cellpadding=0 style="top:0px;left:0px">'
                + '<tr valign=top>'
                + '<td valign=top align=left>' //Image
                + '<div style="padding:6px;">'
                + '<a target=\'_blank\' href=\'' + _amzn_utils.getURL(result['DetailPageURL'], self) + '\'>'
                + '<img src=\'' + imgURL + '\' class=\'asin_img\' hspace=0  style="' + asin_img_style_str + '" />'
                + '</a>'
                + '</div></td>'
                + '<td align=left>'
                + '<div>'  // Details
                + '<table cellspacing="0" cellpadding="0" valign=top style= "width:' + detailWidth+ 'px">'
                + '<tr>'
                + '<td>'
                + '<table cellspacing="0" cellpadding="0" style="width:' + titleWidth +'px">'
                + '<tr>'
                + '<td>'
                + '<a target=\'_blank\' href=\'' + _amzn_utils.getURL(result['DetailPageURL'], self) + '\'>'
		+ '<div class=\'asin_h1\' style="width:'+titleWidth +'px;">' + trimmedTitle + '</div></a>'
                + '</td>'
                + '</tr>'
                + '<tr valign=top>'
                + '<td valign=top>'
                + '<a target=\'_blank\'  href=\'' + _amzn_utils.getURL(result['DetailPageURL'], self) + '\'>'
                + '<div class=\'asin_h2\' style="width:'+titleWidth +'px;">'+ trimmedSubTitle + '</div></a>'
                + '</td></tr>'
                + '<tr valign=top ><td valign=top>' + review
                + '</td>'
                + '</tr>'
                + '</table>'
                + '</td>'
                + '<td align=right valign="top" style="width:18px">'
                + '</td>'
                + '</tr>'
                + '<tr><td valign=left colspan=2>'
                + '<div class="cssbutton" style="' 
				+ 'background:url(\''  
				+ _amzn_utils.imageDirectory(self.marketPlace) + '/btn-right2-sm-sec.gif\') no-repeat right top;'
				+ ' width:' + buy_button_width  + 'px;padding-bottom:9px;">';
                var buyButtonLink = result['DetailPageURL'];
                if(addToCart){
                        buyButtonLink = _amzn_utils.getString(this.AmazonComLink, self.marketPlace) + "gp/aws/cart/add.html?"
                        buyButtonLink+="ASIN.1=" + result['ASIN'] + "&Quantity.1=1&huc=1&SessionId=" + amzn_session_id;
                }
                retObj += '<a target="_blank" href="' + _amzn_utils.getURL(buyButtonLink, self) 
						+ '"><div style="'
						+ 'background:url(\''  
						+ _amzn_utils.imageDirectory(self.marketPlace) + '/btn-mid-slider2-sm-sec.gif\') no-repeat left top;'
						+' width:'+(buy_button_width-7) +'px;"><span class="cssbuttonleft" >'
						+ buyButtonStr + '</span>'
						+ '<span class="cssbuttonright">'+ buyPrice +'</span></div></a>'
						+ '</div>';
                if(hasDigital){
                        retObj+= '<div class="cssbuttonor">-or-</div>'
                        + '<table  cellspacing="0" cellpadding="0"  valign=top><tr valign=top align=left><td valign=top">'
                        + '<div class="cssbutton" style="width:' + dnld_button_width  
			+ 'px;background:url(\'' + _amzn_utils.imageDirectory(self.marketPlace) 
			+ '/btn-right2-sm-sec.gif\') no-repeat right top;">'
                        + '<a target="_blank" href="' + _amzn_utils.getURL('http://www.amazon.com/dp/'+result['DigitalAsin'], self) +'/"><div style="background:url(\'' + _amzn_utils.imageDirectory(self.marketPlace) + '/btn-mid-slider2-sm-sec.gif\') no-repeat left top; width:'+(dnld_button_width-7) +'px;"><span class="cssbuttonleft" >';
                        if(self.marketPlace=="US" && (result["category"] == "Movie" ||result["category"] == "DVD" ||result["category"] == "" || result["category"] == "TV Series Video on Demand" || result["category"] == "TV Series Episode Video on Demand")){    
				retObj+= this.getString(this.WatchNow, self.marketPlace);
                        }else{
                            retObj+= this.getString(this.Download, self.marketPlace);
                        }
                        retObj+= '</span><span class="cssbuttonright">'
                        + downloadPrice +'</span></div></a>'
                        + '</div>'
                        + '</td></tr>'
                        + '<tr><td class="cssbuttontype" align=left>'
                        + this.getString(this.Amazon,self.marketPlace)
                        + digitalCategory
                        + '</td></tr>'
                        + '</table>';
                } // Download button;
                retObj+= '</td>'
                + '</tr></table></div>' //2nd level div.
                + '</td></tr><tr><td colspan = 2>'
                //+ '</table>'
                + commentElement
                + '<div style=\'clear:left\'></div>'
		+ '</td></tr></table>'
                + '</td></tr></table></div>';
                return retObj;
                                                                                                                                                             
    },
	
    getImageURLForDimension: function(imgURL, height, width){
        var suffix = imgURL.substring(imgURL.length - 3);
        return imgURL.substring(0, imgURL.length - 3) + "_SX" + width + "_SY" + height + "_." + suffix;
    },	

    recordImpression: function(tag, linkCode,  marketPlace) {
        var img = document.createElement('IMG');
        img.style.width = '1px';
        img.style.height = '1px';
        img.style.border = 'none';
        var orgUnit = 1;
        switch(marketPlace) {
            case 'US' : orgUnit = 1; break;
            case 'GB' : orgUnit = 2; break;
            case 'DE' : orgUnit = 3; break;
            case 'FR' : orgUnit = 8; break;
            case 'JP' : orgUnit = 9; break;
            case 'CA' : orgUnit = 15; break;
            case 'CN' : orgUnit = 28; break;
            case 'IN' : orgUnit = 31; break;
    	    case 'BR' : orgUnit = 32; break;
        }

		var prefix = "http";

        if (typeof isAmznWC != 'undefined' && (isAmznWC == 1 || isAmznWC == '1')) {
			prefix = "https";
		}

        img.src = prefix + '://' + this.getString("PandaAssocImpVIP", marketPlace) + '/e/ir?'
                + 'o=' + orgUnit
                + '&t=' + tag
                + '&l=' + linkCode;
        document.body.appendChild(img);
        if(marketPlace == 'US') {
            if(prefix != 'https') {
                var ifrm = document.createElement('IFRAME'); 
                var iframe_url="http://g-ec2.images-amazon.com/images/G/01/associates/widgets/20070822/US/html/preload_retail_asset._V386964866_.html";
                ifrm.setAttribute("src", iframe_url);
                ifrm.setAttribute("style", "border:none !important; width: 1px !important; height: 1px !important;");
                ifrm.setAttribute("frameborder", "0");
                ifrm.height = "1";               
                ifrm.width = "1";               
                ifrm.frameBorder = "0";
                setTimeout(function(){ try {document.body.appendChild(ifrm);}  catch(e) {}}, 5000);
            }
	}	
    },

    recordPopover: function(tag, linkCode,  marketPlace, asin) {
        var img = document.createElement('IMG');
        img.style.width = '1px';
        img.style.height = '1px';
        img.style.border = 'none';
        var orgUnit = 1;
        switch(marketPlace) {
            case 'US' : orgUnit = 1; break;
            case 'GB' : orgUnit = 2; break;
            case 'DE' : orgUnit = 3; break;
            case 'FR' : orgUnit = 8; break;
            case 'JP' : orgUnit = 9; break;
            case 'CA' : orgUnit = 15; break;
            case 'CN' : orgUnit = 28; break;
        }

		var prefix = "http";

        if (typeof isAmznWC != 'undefined' && (isAmznWC == 1 || isAmznWC == '1')) {
			prefix = "https";
		}

        img.src = prefix + '://' + this.getString("PandaAssocImpVIP", marketPlace) + '/s/pp?'
                + 'o=' + orgUnit
                + '&t=' + tag
                + '&l=' + linkCode
                + '&asin=' + asin;
        document.body.appendChild(img);
    },

    getABTreatment:function() {
        if (typeof Math != 'undefined' && typeof Math.random != 'undefined') {
            var rand = Math.random();
            return rand < 0.5;
        }
        return true;
    },	

    getAmazonLogoDimensions: function(marketPlace) {
        var result = new Object();
        switch(marketPlace) {
            case 'CA':
                result.height = 27;
                result.width = 89;
                break;
            case 'DE':
                result.height = 26;
                result.width = 88;
                break;
            case 'FR':
                result.height = 28;
                result.width = 89;
                break;
            case 'GB':
                result.height = 22;
                result.width = 84;
                break;
            case 'JP':
                result.height = 23;
                result.width = 87;
                break;
            default:
                result.height = 22;
                result.width = 86;
                break;
        }

        return result;
    },

    getGetWidgetButtonDimensions: function(marketPlace) {
        var result = new Object();
        switch(marketPlace) {
            case 'DE':
                result.height = 18;
                result.width = 95;
                break;
            case 'FR':
                result.height = 18;
                result.width = 79;
                break;
            case 'JP':
                result.height = 18;
                result.width = 94;
                break;
            default:
                result.height = 18;
                result.width = 82;
                break;
        }

        return result;
    },

    getRevampGetWidgetButtonDimensions: function(marketPlace) {
        var result = new Object();
        switch(marketPlace) {
            case 'DE':
                result.height = 17;
                result.width = 89;
                break;
            case 'FR':
                result.height = 17;
                result.width = 78;
                break;
            case 'JP':
                result.height = 17;
                result.width = 87;
                break;
            default:
                result.height = 17;
                result.width = 70;
                break;
        }

        return result;
    },

    drawFooter:function(self) {
        var logoImage;
        var linkColor;
        var bgColor = new Color(self.getBackgroundColor().substring(1));
        if( bgColor.isDark() ) {
            logoImage = 'amazon-logo-w_tpng.png';
            linkColor = '#FFFFFF';
        } else {
            logoImage = 'amazon-logo-b_tpng.png';
            linkColor = '#000000';
        }

        var footerHeight = 32;
        var width = self.getWidth();
        var privacyLinkFloat = 'left';
        var getButtonClearStyle = '';
        var minWidth = 230;
 
        if( width < 132 ) {
            footerHeight = 60;
        } else if( width < 230 ) {
            footerHeight = 50;
        }

        switch(self.marketPlace) {
            case 'CA':
                footerHeight = 32;
                minWidth = 240;
                if( width < 130 ) {
                    footerHeight = 65;
                } else if( width < minWidth) {
                    footerHeight = 54;
                }
                break;
            case 'DE':
                minWidth = 260;
                footerHeight = 31;
                if( width < 175 ) {
                    footerHeight = 71;
                } else if( width < minWidth ) {
                    footerHeight = 53;
                }
                break;
            case 'FR':
                minWidth = 250;
                footerHeight = 33;
                if( width < 150 ) {
                    footerHeight = 65;
                } else if( width < minWidth ) {
                    footerHeight = 55;
                }
                break;
            case 'GB':
                break;
            case 'JP':
                minWidth = 270;
                if( width < 190 ) {
                    footerHeight = 68;
                } else if(width < minWidth){
                    footerHeight = 50;
                }
                break;
            default:
                break;
        }
        if(self.isIAB){
        	if(self.wdgt_height == 150){
        		footerHeight = 26;
        	}else if(self.width > 180){
        		footerHeight = 37;
        	}else{
        		footerHeight = 52;
        	}
        	if(_amzn_utils.isFirefox() && (self.wdgt_height==250 || self.wdgt_height==280) && self.marketPlace=='FR'){
        		footerHeight++;
        	}
        }
        
        if( width < minWidth ) {
            privacyLinkFloat = 'right';
            getButtonClearStyle = 'clear: left; ';
        }
        
        var PrivacyPolicyLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLinkLength, self.marketPlace));
        var AmazonComLogoLength =  parseInt(_amzn_utils.getString(_amzn_utils.AmazonComLogoLength, self.marketPlace));
        var GetLinkButtonLength = parseInt(_amzn_utils.getString(_amzn_utils.GetLinkButtonLength, self.marketPlace));
        var GetLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.GetLinkLength, self.marketPlace));
        var PrivacyAmazonComPermissableLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyAmazonComPermissableLength, self.marketPlace));
        var PrivacyGetLinkPermissableLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyGetLinkPermissableLength, self.marketPlace));
        var LetterToPixelRatio = parseInt(_amzn_utils.getString(_amzn_utils.LetterToPixelRatio, self.marketPlace));
        var PrivacyGetLinkButtonPermissableLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyGetLinkButtonPermissableLength, self.marketPlace));

        PrivacyPolicyLinkLength = PrivacyPolicyLinkLength * LetterToPixelRatio;
        GetLinkLength = GetLinkLength * LetterToPixelRatio;
        if (width > minWidth)   {
                PrivacyGetLinkButtonPermissableLength = PrivacyGetLinkButtonPermissableLength + (width-minWidth);

        }
        var GetLinkVisible = true;
        var GetLinkButtonVisible = true;
        var AmazonComVisible = true;

        if(PrivacyGetLinkButtonPermissableLength < PrivacyPolicyLinkLength + GetLinkButtonLength )
                    GetLinkButtonVisible  = false;
        if(PrivacyAmazonComPermissableLength < PrivacyPolicyLinkLength + AmazonComLogoLength )
                    AmazonComVisible  = false;
        if(PrivacyGetLinkPermissableLength < PrivacyPolicyLinkLength + GetLinkLength )
                    GetLinkVisible  = false;

       
        var logoLinkContent;
        if( self.showAmazonLogoAsText ) {
            logoLinkContent = _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace);
        } else {
            logoLinkContent = '<img height="' + this.getAmazonLogoDimensions(self.marketPlace).height + '" width="' + this.getAmazonLogoDimensions(self.marketPlace).width + '" border="0" alt="'+ _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace)
                    + '" src="' + _amzn_utils.imageDirectory(self.marketPlace) + '/' + logoImage + '"/>';
        }
        if(self.isIAB && self.wdgt_height == 150){
        	logoLinkContent = "";
        }
        var res = '<div id="wdgt_ft" class=\'wdgt_ft\' style=\'height: ' + footerHeight + 'px;';
        var temp = '';
        var getWidgetFontSize="10px;";
		if(self.isIAB && self.marketPlace == "JP"){
				getWidgetFontSize="8px";
		}
        if(self.isIAB){
        	if(self.wdgt_height == 150){
        		res+='padding: 0px 5px 0px 3px; ' + self.style_wdgt_ft() + ';\'>';
        	}else{
        		res+='padding: 0; ' + self.style_wdgt_ft() + ';\'>';
        	}
            if(self.wdgt_height == 150){
            	temp = '<div class=\'ft_cnt\'>';
                if(AmazonComVisible) {
                temp += '<img align=left height="' + this.getAmazonLogoDimensions(self.marketPlace).height + '" width="' + this.getAmazonLogoDimensions(self.marketPlace).width + '" border="0" alt="'+ _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace)+ '" src="' + _amzn_utils.imageDirectory(self.marketPlace) + '/' + logoImage + '"/>';
            }
            }else{
                temp += '<div class=\'ft_cnt\'><a target="_blank" style="padding-left:4px;padding-right:5px;padding-top:2px;text-decoration: none; clear:left; float: left;font-size:' + getWidgetFontSize +';color:'
                + self.getGetWidgetColor() ;

                if(GetLinkVisible)  {
    				temp +=  '" href="'
	                + _amzn_utils.getString(_amzn_utils.WebsiteUrl, self.marketPlace) + '/' + self.getEditWidgetTarget
	                            + '">' + _amzn_utils.getString(_amzn_utils.GetWidgetLong, self.marketPlace) + '</a>';
                }
            }
        } else{  
        	res+='padding: 5px 5px 5px 3px; ' + self.style_wdgt_ft() + ';\'>';       
              
	        temp += '<div class=\'ft_cnt\'>';
            if(GetLinkButtonVisible)  {
                    temp +=  '<a target="_blank" style="text-decoration: none; clear:left; float: left;font-size:10px;color:' + self.head_text_color + '" href="'
                        + _amzn_utils.getString(_amzn_utils.WebsiteUrl, self.marketPlace) + '/' + self.getEditWidgetTarget
                        + '"><img ' + ' width="' + this.getGetWidgetButtonDimensions(self.marketPlace).width + '" height="' + this.getGetWidgetButtonDimensions(self.marketPlace).height + '" border="0" alt="Get Widget"'
                    + 'border="0" src="'+ _amzn_utils.imageDirectory(self.marketPlace) + '/btn-get-widget_tpng.png"/>' + '</a>';
            }
		}
		
        temp += '<a target="_blank" style="padding: 2px 0 0 0px; text-decoration: none; float: ' + privacyLinkFloat + '; font-size: ' + getWidgetFontSize +'; color: #' +  bgColor.getBlendingColor().getHex() + ' !important;" '
                    + 'href="' + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLink, self.marketPlace), self) + '">'
                    + _amzn_utils.getString(_amzn_utils.PrivacyPolicy, self.marketPlace) + '</a>';

		if(self.isIAB && self.wdgt_height == 150){
			res+=temp;
		}
        else if(!GetLinkVisible && !AmazonComVisible) {
            res+=temp;
        }
        else if(!GetLinkVisible || width > minWidth) {
            var floatvalue ='right';
            if(width < minWidth)
                floatvalue ='left';
            res = res + temp + '<a target="_blank" style="text-decoration: none; float:'+ floatvalue +';' + floatvalue +': 5px; font-size:12px; color: '+ linkColor + ' !important; " href="'
                    + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.AmazonComLink, self.marketPlace) + "?", self) + '">'
                    + logoLinkContent + '</a>'
   
        }
        else if( width < minWidth ) {
            res = res + '<a target="_blank" style="text-decoration: none; float: left; font-size:12px; color: '+ linkColor + ' !important; " href="'
                    + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.AmazonComLink, self.marketPlace) + "?", self) + '">'
                    + logoLinkContent + '</a><br/>' + temp;
        } 
        res += '</div></div>';
        return res;
    },

    drawRevampFooter: function(self, isDarkBackground) {

        var GetLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.GetLinkLength, self.marketPlace));
        var PrivacyPolicyLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLinkLength, self.marketPlace));
        var AmazonComLogoLength =  parseInt(_amzn_utils.getString(_amzn_utils.AmazonComLogoLength, self.marketPlace));
        var PrivacyAmazonComPermissableLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyAmazonComPermissableLength, self.marketPlace));
        var LetterToPixelRatio = parseInt(_amzn_utils.getString(_amzn_utils.LetterToPixelRatio, self.marketPlace));

        PrivacyPolicyLinkLength = PrivacyPolicyLinkLength * LetterToPixelRatio;
        GetLinkLength = GetLinkLength * LetterToPixelRatio;

        var AmazonComVisible = true;

        if(PrivacyAmazonComPermissableLength < PrivacyPolicyLinkLength + AmazonComLogoLength )
                    AmazonComVisible  = false;


        var logoLinkContent;
        var logoColor;
        var logoImage;
        if(isDarkBackground ) {
            logoColor = "#FFFFFF";
            logoImage = "amazon-logo-w_tpng.png";
        } else {
            logoColor = "#000000";
            logoImage = "amazon-logo-b_tpng.png";
        }
        if( self.showAmazonLogoAsText ) {
            logoLinkContent = _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace);
        } else {
            logoLinkContent = '<img height="' + this.getAmazonLogoDimensions(self.marketPlace).height + '" style=\'top: 5px;\' width="' +
                              this.getAmazonLogoDimensions(self.marketPlace).width + '" border="0" alt="'+ _amzn_utils.getString(_amzn_utils.AmazonCom, self.marketPlace)
                    + '" src="' + _amzn_utils.imageDirectory(self.marketPlace) + '/' + logoImage + '"/>';
        }
        var res = '<div id="wdgt_ft" class=\'wdgt_ft\' style=\'padding:0px; width:100%;' + self.style_wdgt_ft() + ';\'>';
        var getWidgetFontSize="10px;";
	var innerDivHeight = 'style="height:26px;"';
		if(self.isIAB && self.marketPlace == "JP"){
				getWidgetFontSize="8px";
		}
		if(self.isIAB && self.wdgt_height == 150){
			var logoHeight = this.getAmazonLogoDimensions(self.marketPlace).height;
			var topPadding = 28 - logoHeight;
			res = '<div class=\'wdgt_ft\' style=\'padding:' + topPadding + 'px 0px 0px 0px; width:100%;' + self.style_wdgt_ft() + '\'>';
			innerDivHeight='style="height:' + (28 - topPadding ) + 'px;"'
		}	
        if((self.isIAB && (AmazonComVisible ||  self.width < 180)) || !self.isIAB ) {
        res+= '<div class=\'new_ft_cnt\'' + innerDivHeight + '>'
                + '<a target=\'_blank\' style=\'color: ' + logoColor + ' !important; width:90px;text-align:left; float: left;\' href=\''
                + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.AmazonComLink, self.marketPlace) + "?", self) + '\'>'
                + logoLinkContent
                + '</a> ';
        }
        
        if(!self.isIAB || self.width > 160){
		        res += '<a target=\'_blank\' onmouseover=\'\' style=\'float:right; text-align:right;' + self.style_wdgt_ft() + ';font-size:' + getWidgetFontSize 
	        	        +';padding:2px 0px 0px 0px;\' href=\'' + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLink, self.marketPlace), self) + '\'>'
		                + _amzn_utils.getString(_amzn_utils.PrivacyPolicy, self.marketPlace) + '</a>';
		}
        res += '</div></div>';
        return res;
    },

    drawRevampGetWidgetAndEdit: function(self, getWidgetButton) {

        var GetLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.GetLinkLength, self.marketPlace));
        var PrivacyPolicyLinkLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLinkLength, self.marketPlace));
        var PrivacyGetLinkPermissableLength = parseInt(_amzn_utils.getString(_amzn_utils.PrivacyGetLinkPermissableLength, self.marketPlace));
        var LetterToPixelRatio = parseInt(_amzn_utils.getString(_amzn_utils.LetterToPixelRatio, self.marketPlace));

        PrivacyPolicyLinkLength = PrivacyPolicyLinkLength * LetterToPixelRatio;
        GetLinkLength = GetLinkLength * LetterToPixelRatio;

        var GetLinkVisible = true;

        if(PrivacyGetLinkPermissableLength < PrivacyPolicyLinkLength + GetLinkLength )
                    GetLinkVisible  = false;



        var res = '';
        var btnDimensions = _amzn_utils.getRevampGetWidgetButtonDimensions(self.marketPlace);
        var getWidgetFontSize="10px;";
		if(self.isIAB && self.marketPlace == "JP"){
				getWidgetFontSize="8px";
		}
        res += '<table width="100%">'
                + '<tr style=\'vertical-align:middle;\'>';
        if(GetLinkVisible || self.isIAB)  {
                + '<td align="left">'
                + '<a target="_blank" style="text-decoration: none; clear:left; float: left;" href="'
                + _amzn_utils.getString(_amzn_utils.WebsiteUrl, self.marketPlace) + '/' + self.getEditWidgetTarget
                + '">'
                + '<img width="'
                + btnDimensions.width + '" height="' + btnDimensions.height + '" border="0" align="absmiddle" alt="'
                + _amzn_utils.getString(_amzn_utils.GetEditWidgetShort, self.marketPlace) + '"'
                + 'src="' + _amzn_utils.imageDirectory(self.marketPlace) + '/' + getWidgetButton + '"/>'
                + '</a>'
                + '</td>';
         }
         if(self.isIAB){
                res = '<table width="100%">'
                + '<tr style=\'vertical-align:middle;\'>'
                + '<td align="left">'
                + '<a target="_blank" style="text-decoration: none; clear:left; float: left;font-size:' + getWidgetFontSize + ';color:' + self.head_text_color + '" href="'
                + _amzn_utils.getString(_amzn_utils.WebsiteUrl, self.marketPlace) + '/' + self.getEditWidgetTarget
                + '">'
                + _amzn_utils.getString(_amzn_utils.GetWidgetLong, self.marketPlace);
                + '</a>'
                + '</td>';
		if(self.width <= 160 && self.isIAB){
			res+='<td align="right">';
			 res += '<a target=\'_blank\' onmouseover=\'\' style=\'float:right; text-align:right;' +'font-size:' + getWidgetFontSize + ';color:' + self.head_text_color +';\' href=\'' + _amzn_utils.getURL(_amzn_utils.getString(_amzn_utils.PrivacyPolicyLink, self.marketPlace), self) + '\'>'
                        + _amzn_utils.getString(_amzn_utils.PrivacyPolicy, self.marketPlace) + '</a></td>';
		}
        }
        res += '</tr></table>';

        return res;
    },

    widgetServerURL: function(marketPlace) {
        var wsURL = this.getString("PandaWSUrl", marketPlace);
        if (typeof isAmznWC != 'undefined' && (isAmznWC == 1 || isAmznWC == '1')) {
            wsURL = wsURL.replace(/^http:\/\//, "https://");
        }
        return wsURL;
    },

    amznMediaserverURL: function(marketPlace) {
        var wmsURL = this.getString("PandaWMSUrl", marketPlace);
        if (typeof isAmznWC != 'undefined' && (isAmznWC == 1 || isAmznWC == '1')) {
            wmsURL = wmsURL.replace(/^http:\/\//, "https://");
        }
        return wmsURL;
    },

    imageDirectory: function(marketPlace) {
        return this.amznMediaserverURL(marketPlace) + '/' + marketPlace + '/img';
    },
    
    getURL : function(urlIn, self) {
        var urlParts = urlIn.split('?', 2);
        var url = this.addRefTagToURL(urlParts[0], self) + '?';
        if(urlParts[1]){ url += urlParts[1]; } // add the query parameters
      
        url += '&linkCode=' + self.linkCode + '&tag=' + self.tag;
        
        return url;
    },

    addRefTagToURL: function(url, self) {
        var params = self.origParams;
        var reftag = (params['rt'])? params['rt'] : null;
        var result;
        if (reftag != null && url.search(/\/ref=/) == -1) {
            if (url.charAt(url.length - 1) != '/') {
                url += '/';
            }
            result = url + 'ref=' + reftag;
        } else {
            result = url;
        }
        return result;
    },

    ErrorMessage: 'ErrorMessage',
    Price: 'Price',
    Loading: 'Loading',
    Searching: 'Searching',
    PrivacyPolicy: 'PrivacyPolicy',
    NoResultsFor: 'NoResultsFor',
    CustomerReviews: 'CustomerReviews',
    Search: 'Search',
    Showing: 'Showing',
    
    AssocImpVIP: 'AssocImpVIP',
    AmazonCom: 'AmazonCom',
    AmazonComLink: 'AmazonComLink',
    PrivacyPolicyLink: 'PrivacyPolicyLink',
    WSUrl: 'WSUrl',
    WMSUrl: 'WMSUrl',
    WebsiteUrl: 'WebsiteUrl',
    GetEditWidgetShort: 'GetEditWidgetShort',
    GetEditWidgetLong: 'GetEditWidgetLong',
    GetWidgetLong: 'GetWidgetLong',	
    selectStore: 'SelectStore',
    closeString: 'CloseWindow',
    SortBy: 'SortBy',
    DVD: 'DVD',
    Music: 'Music',
    Book: 'Book',
    Video: 'Video',
    Download: 'Download',
    WatchNow: 'WatchNow',
    Buy: 'Buy',
    Now: 'Now',	
    Kindle: 'Kindle',	
    MP3: 'MP3',	
    Unbox: 'Amazon Instant Video',
    Amazon: 'Amazon',		
    NoItemsWishlist: 'NoItemsWishlist',
    DefaultTag: 'DefaultTag',
    WebsiteRefTag: 'WebsiteRefTag',
    WebsiteRefParam: 'ref',
    CompletionVIP: 'CompletionVIP',
    issMktid: 'issMktid',
    PrivacyPolicyLinkLength : 'PrivacyPolicyLinkLength',
    AmazonComLogoLength : 'AmazonComLogoLength',
    GetLinkButtonLength : 'GetLinkButtonLength',
    GetLinkButtonLengthDark : 'GetLinkDarkButtonLength',
    GetLinkLength : 'GetLinkLength',
    AmazonComPermissableLength : 'AmazonComPermissableLength',
    PrivacyGetLinkPermissableLength : 'PrivacyGetLinkPermissableLength',
    PrivacyGetLinkButtonPermissableLength : 'PrivacyGetLinkButtonPermissableLength',
    PrivacyAmazonComPermissableLength : 'PrivacyAmazonComPermissableLength',
    LetterToPixelRatio : 'LetterToPixelRatio',
    PrivacyGetLinkButtonPermissableLengthDark : 'PrivacyGetLinkButtonPermissableLengthDark',
    
    getString: function(key, marketPlace) {
          
          switch(marketPlace) {
            case 'CA' :  return _amzn_utils_strs.getStringForCA(key);
            case 'CN' :  return _amzn_utils_strs.getStringForCN(key);
            case 'DE' :  return _amzn_utils_strs.getStringForDE(key);
            case 'FR' :  return _amzn_utils_strs.getStringForFR(key);
            case 'JP' :  return _amzn_utils_strs.getStringForJP(key);
            case 'GB' :  return _amzn_utils_strs.getStringForGB(key);
            case 'IN' :  return _amzn_utils_strs.getStringForIN(key);
            case 'BR' :  return _amzn_utils_strs.getStringForBR(key);
            default :  return _amzn_utils_strs.getStringForUS(key);
        }

    
   },

    trimMultiLineComments: function(textArray, fontType, width, requiredNumOfLines, self) {
        if (typeof textArray == 'string') {
            textArray = [textArray];
        }
        if(textArray.length < 1 ) {
            return textArray;
        }
        if (!requiredNumOfLines) {
            requiredNumOfLines = 1;
        }

        var escapedText = textArray[0];
        for( var i = 1; i < textArray.length; i++) {
            escapedText += '<br/>'+ textArray[i];
        }
        escapedText = escapedText.replace(/&nbsp;/gi,'&nbsp;<wbr/>');

        var result;
        if( requiredNumOfLines == -1) {
            result = _amzn_utils.splitTextBlock(escapedText, fontType, width, false, self);
        } else {
            result = _amzn_utils.trimTextBlock(escapedText, fontType, width, requiredNumOfLines, false, self);
        }

        return result;
    },

    trimCharsByWidth: function(textArray, fontType, width, requiredNumOfLines, self) {
        if (typeof textArray == 'string') {
            textArray = [textArray];
        }
        if(textArray.length < 1 ) {
            return textArray;
        }
        if (!requiredNumOfLines) {
            requiredNumOfLines = 1;
        }

        var escapedText = textArray[0];

        for( var i = 1; i < textArray.length; i++) {
            if( i % 2 == 0 ) {
                escapedText += ' ' + textArray[i];
            } else {
                escapedText += '<b> '+ textArray[i] + ' </b>';
            }
        }
        escapedText = escapedText.replace(/&nbsp;/gi,'&nbsp;<wbr/>');

        var isBoldTagPresent = textArray.length > 1 ;
        var result;
        if( requiredNumOfLines == -1) {
            result = _amzn_utils.splitTextBlock(escapedText, fontType, width, isBoldTagPresent, self);
        } else {
            result = _amzn_utils.trimTextBlock(escapedText, fontType, width, requiredNumOfLines, isBoldTagPresent, self);
        }

        return result;
    },

    getValidTextBoundary: function(txt, endIndex) {
        if( endIndex >= txt.length ) {
            return txt.length;
        }

        var validText = txt.substring(0, endIndex);
        var validTextBoundary = endIndex;

        //For HTML tags
        var lastTagStart = validText.lastIndexOf('<');
        if( lastTagStart != -1 ) {
            var lastBreak = validText.lastIndexOf('<br/>');
            var lastWordBreak = validText.lastIndexOf('<wbr/>');
            var lastOpenBold = validText.lastIndexOf('<b>');
            var lastCloseBold = validText.lastIndexOf('</b>');

            if( lastTagStart > lastBreak &&
                lastTagStart > lastWordBreak &&
                lastTagStart > lastOpenBold &&
                lastTagStart > lastCloseBold) {
                validTextBoundary = lastTagStart;
                validText = txt.substring(0, validTextBoundary);
            }
        }

        //For escape sequences
        var lastEscapeSeqStart = validText.lastIndexOf('&');
        if( lastEscapeSeqStart != -1 ) {
            var lastEscapeSeqEnd = validText.lastIndexOf(';');
            if( lastEscapeSeqStart > lastEscapeSeqEnd ) {
                validTextBoundary = lastEscapeSeqStart;
            }
        }

        return validTextBoundary;
    },

    getClosingTags: function(txt, isBoldTagPresent) {
        if(!isBoldTagPresent) {
            return '';
        }

        var lastOpenBold = txt.lastIndexOf('<b>');
        var lastCloseBold = txt.lastIndexOf('</b>');

        var closingTag = '';
        if( lastCloseBold < lastOpenBold) {
            closingTag = '</b>';
        }

        return closingTag;
    },

    limitedIndexOf: function(txt, searchChar) {
        var limit = 15;
        var endIndex = 0;
        var found = false;

        while(endIndex < txt.length && endIndex < limit) {
            if( txt.charAt(endIndex) == searchChar ) {
                found = true;
                break;
            }
            endIndex++;
        }
        if(!found) {
            endIndex = -1;
        }

        return endIndex;
    },

    htmlCharAt: function(txt, index) {
        var searchChar = '';
        var charAtIndex = txt.charAt(index);

        switch(charAtIndex) {
            case '<':
                    searchChar = '>';
                    break;
            case '&':
                    searchChar = ';';
                    break;
        }

        if( searchChar != '' ) {
            var searchSegment = txt.substring(index);
            var closeTagIndex = _amzn_utils.limitedIndexOf(searchSegment, searchChar);
            if( closeTagIndex != -1 ) {
                charAtIndex = searchSegment.substring(0, closeTagIndex + 1);
            }
        }

        return charAtIndex;
    },

    calculateBlockHeight: function(text, fontType, numLines, isBoldTagPresent, self) {
        var divId = _amzn_utils.getDivId('amzn_wdgts_calculateBlockHeight', self);
        var tempDiv = _amzn_utils.getProcessingDiv(divId, fontType);
	if(self.marketPlace == "JP"){
	        tempDiv.innerHTML = 'Apple iPod classic 120GB ブラック'; //JP chars are taller so init height is high. Doing this to ensure that
	}else{
	        tempDiv.innerHTML = '';
	}
        var initHeight = tempDiv.offsetHeight;

        var tempText = text;
        if( isBoldTagPresent ) {
            tempText = _amzn_utils.replaceAll(tempText,'<b>','');
            tempText = _amzn_utils.replaceAll(tempText,'</b>','');
        }
        tempText = _amzn_utils.replaceAll(tempText,'<br/>','');
        tempText = _amzn_utils.replaceAll(tempText,'<wbr/>','');

        var maxLineHeight = 0;
        var segmentLength = 20;
        while(tempText.length > 0) {
            var endIndex = segmentLength < tempText.length ? segmentLength : tempText.length;
            endIndex = _amzn_utils.getValidTextBoundary(tempText, endIndex);

            var segment = tempText.substring(0, endIndex);
            if( isBoldTagPresent ) {
                tempDiv.innerHTML = '<b>' + segment + '</b>';
            } else {
                tempDiv.innerHTML = segment;
            }
            if( tempDiv.offsetHeight > maxLineHeight ) {
                maxLineHeight = tempDiv.offsetHeight;
            }

            tempText = tempText.substring(endIndex);
        }

        var blockHeight = 0;
        if( maxLineHeight - 2 > initHeight ) {
            maxLineHeight = maxLineHeight - initHeight;
            blockHeight = maxLineHeight * numLines - initHeight;
        } else {
            blockHeight = maxLineHeight * numLines;
        }

        return blockHeight;
    },
    getTextHeightAndWidth: function(text, font, fontSize, isBold, className , self){
	if( !text || text == '') {
	    return [0, 0];
	}
	var trimDivId = _amzn_utils.getDivId('amzn_wdgts_trimTextBlock', self);
	var pDiv = _amzn_utils.getProcessingDiv(trimDivId, fontSize);
	pDiv.className = className;
	pDiv.style.font = font;
	pDiv.style.fontSize = parseInt(fontSize) + 'px';
	if(isBold){
	        pDiv.style.fontWeight="bold";
	}
	pDiv.style.padding='0px 0px 0px 0px';
	                                                                                                                                                     
	pDiv.innerHTML= text;
	ret =  [pDiv.offsetHeight,pDiv.offsetWidth];
	pDiv.className="";
	return ret;
    }, 
    trimTextBlock: function(text, fontType, width, numLines, isBoldTagPresent, self) {
        if( !text || text == '') {
            return text;
        }

        var trimDivId = _amzn_utils.getDivId('amzn_wdgts_trimTextBlock', self);
        var trimmerDiv = _amzn_utils.getProcessingDiv(trimDivId, fontType);
        trimmerDiv.style.width = width + 'px';
        trimmerDiv.innerHTML = 'X';
        var initScrollWidth = trimmerDiv.scrollWidth;
        var blockHeightPix =  _amzn_utils.calculateBlockHeight(text, fontType, numLines, false, self);
        if( isBoldTagPresent ) {
            var boldBlockHeightPix =  _amzn_utils.calculateBlockHeight(text, fontType, numLines, true, self);
            if( boldBlockHeightPix > blockHeightPix ) {
                blockHeightPix = boldBlockHeightPix;
            }
        }
        if( blockHeightPix <= 0 ) {
            return '';
        }

        var result = text;
        trimmerDiv.innerHTML = result;
        var previousLength = result.length;
        while(trimmerDiv.offsetHeight > blockHeightPix) {
            var ratio = trimmerDiv.offsetHeight / blockHeightPix;

            var length = Math.round((result.length)/ratio);
            length = _amzn_utils.getValidTextBoundary(result, length);
            if( length == previousLength ) {
                break;
            }
            previousLength = length;

            result = result.substring(0, length);
            trimmerDiv.innerHTML = result + _amzn_utils.getClosingTags(result, isBoldTagPresent);

        }

        for( var i = result.length; i < text.length; i++ ) {
            var temp = _amzn_utils.htmlCharAt(text, i);
            i += temp.length - 1;

            trimmerDiv.innerHTML = result + temp + _amzn_utils.getClosingTags(result + temp, isBoldTagPresent) + '&hellip;';
            if( trimmerDiv.scrollWidth > initScrollWidth ) {
                temp = ' ' + temp;
                trimmerDiv.innerHTML = result + temp + _amzn_utils.getClosingTags(result + temp, isBoldTagPresent) + '&hellip;';
            }
            if( trimmerDiv.offsetHeight > blockHeightPix) {
                result = result + _amzn_utils.getClosingTags(result, isBoldTagPresent) + '&hellip;'
                break;
            }

            result += temp;
        }
        result = result + _amzn_utils.getClosingTags(result, isBoldTagPresent);
        result = _amzn_utils.splitTextBlock(result, fontType, width, isBoldTagPresent, self)

        trimmerDiv.innerHTML = result;
        if( trimmerDiv.offsetHeight > blockHeightPix) {
            trimmerDiv.innerHTML =  result + '&hellip;';
            var length = result.length;
            while(length > 0 && (trimmerDiv.offsetHeight > blockHeightPix || trimmerDiv.scrollWidth > initScrollWidth)) {
                length--;
                length = _amzn_utils.getValidTextBoundary(result, length);
                result = result.substring(0,length);
                trimmerDiv.innerHTML =  result + _amzn_utils.getClosingTags(result, isBoldTagPresent) + '&hellip;';
            }
            result = result + _amzn_utils.getClosingTags(result, isBoldTagPresent) + '&hellip;'
        }

        return result;
    },

    setDivText: function(tdiv, text, isBoldTagPresent) {
        var temp = _amzn_utils.getClosingTags(text, isBoldTagPresent);
        tdiv.innerHTML = text + temp;

        return temp != '';
    },

    splitTextBlock: function(text, fontType, width, isBoldTagPresent, self) {
        if( !text || text == '') {
            return text;
        }

        var trimDivId = _amzn_utils.getDivId('amzn_wdgts_splitTextBlock', self);
        var trimmerDiv = _amzn_utils.getProcessingDiv(trimDivId, fontType);
        trimmerDiv.style.width = width + 'px';
        trimmerDiv.innerHTML = '';
        var initHeight = trimmerDiv.offsetHeight;
        trimmerDiv.innerHTML = 'X';
        var height = trimmerDiv.offsetHeight;
        var initScrollWidth  = trimmerDiv.scrollWidth;

        trimmerDiv.innerHTML = text;
        if( trimmerDiv.scrollWidth <= initScrollWidth ) {
            return text;
        }

        var numCharsPerLine = Math.floor(width / 20); //Assuming a max character width of 20
        trimmerDiv.innerHTML = '';

        var result = '';
        var boldStarted = false;

        var lastEndIndex = _amzn_utils.getLineEndIndex(text, 0, numCharsPerLine, fontType, width, isBoldTagPresent, boldStarted, self);
        result = text.substring(0, lastEndIndex);
        boldStarted = _amzn_utils.setDivText(trimmerDiv, result, isBoldTagPresent);

        var endIndex = _amzn_utils.getLineEndIndex(text, lastEndIndex, numCharsPerLine, fontType, width, isBoldTagPresent, boldStarted, self);

        while(endIndex > 0 && endIndex > lastEndIndex ) {
            var temp = text.substring(lastEndIndex, endIndex);
            boldStarted = _amzn_utils.setDivText(trimmerDiv, result + temp, isBoldTagPresent);
            if( trimmerDiv.scrollWidth > initScrollWidth ) {
                temp = ' ' + temp;
                _amzn_utils.setDivText(trimmerDiv, result + temp, isBoldTagPresent);
            }

            numCharsPerLine = endIndex - lastEndIndex;
            lastEndIndex = endIndex;
            result = result + temp;
            endIndex = _amzn_utils.getLineEndIndex(text, lastEndIndex, numCharsPerLine, fontType, width, isBoldTagPresent, boldStarted, self);
        }

        return result + _amzn_utils.getClosingTags(result, isBoldTagPresent);
    },

    getLineEndIndex: function(txt, startIndex, approxCharsPerLine, fontType, widthPix, isBoldPresent, isBoldStarted, self) {
        var divId = _amzn_utils.getDivId('amzn_wdgts_getLineText', self);
        var constHtDiv = _amzn_utils.getProcessingDiv(divId, fontType);

        var endIndex = startIndex + approxCharsPerLine + 1;
        var bold = '';
        if( isBoldStarted ) {
            bold = '<b>';
        }
        if( txt.length < endIndex) {
            _amzn_utils.setDivText(constHtDiv, bold + txt.substring(startIndex), isBoldPresent);
            endIndex = txt.length;
        } else {
            _amzn_utils.setDivText(constHtDiv, bold + txt.substring(startIndex, endIndex), isBoldPresent);
        }
        var height = constHtDiv.offsetHeight;

        for( ; endIndex < txt.length && constHtDiv.offsetWidth < widthPix && constHtDiv.offsetHeight <= height; endIndex++) {
            var temp = _amzn_utils.htmlCharAt(txt, endIndex);
            endIndex += temp.length - 1;

            _amzn_utils.setDivText(constHtDiv, bold + constHtDiv.innerHTML + temp, isBoldPresent);
        }

        endIndex = (endIndex < txt.length) ? endIndex : txt.length;
        endIndex = _amzn_utils.getValidTextBoundary(txt.substring(startIndex), endIndex-startIndex) + startIndex;
        while(constHtDiv.offsetWidth > widthPix && endIndex > 0) {
            endIndex--;
            endIndex = _amzn_utils.getValidTextBoundary(txt.substring(startIndex), endIndex-startIndex) + startIndex;
            _amzn_utils.setDivText(constHtDiv, bold + txt.substring(startIndex, endIndex), isBoldPresent);
        }

        return endIndex;
    },

    getProcessingDiv: function(id, fontType) {
        var pDiv = document.getElementById(id);
        var isPresent = true;

        if( !pDiv ) {
            isPresent = false;
            pDiv = document.createElement('div');
            pDiv.id = id;
        }

        pDiv.style.padding = '0 5px 0 5px';
        pDiv.style.visibility = 'hidden';
        pDiv.style.clear = 'both';
        pDiv.style.position = 'absolute';
        pDiv.style.left = '0px';
        pDiv.style.top = '0px';
        pDiv.style.overflow = 'auto';
        pDiv.style.font = '100% Verdana, Arial, Helvetica, sans-serif';
        pDiv.style.lineHeight = 'normal';
        pDiv.style.fontSize = parseInt(fontType) + 'px';
        pDiv.style.height = null;
        pDiv.style.width = null;
        if( /bold/.test(fontType) ) {
            pDiv.style.fontWeight = 'bold';
        }

        if(!isPresent) {
            document.body.appendChild(pDiv);
        }

        return pDiv;
    },

    getDivId: function(prefix, self) {
        return prefix + self.marketPlace + self.templateId + self.instanceId;
    },

    addHiddenInputField: function(formElement, fieldName, fieldValue) {
        var inputElement = document.createElement("input");
        inputElement.setAttributeNode(this.createHtmlAttribute("type", "hidden"));
        inputElement.setAttributeNode(this.createHtmlAttribute("name", fieldName));
        inputElement.setAttributeNode(this.createHtmlAttribute("value", fieldValue));
        formElement.appendChild(inputElement);
    },

    createHtmlAttribute: function(name, value) {
        var attribute = document.createAttribute(name);
        attribute.nodeValue = value;
        return attribute;
    },

    addHtmlForm: function(actionValue) {
        var formElement = document.createElement("form")
        formElement.method = "POST"
        formElement.action = actionValue
        var body = document.getElementsByTagName("body")[0]
        body.appendChild(formElement)
        return formElement
    },

    getValidParam: function(param, defaultValue) {
        if( typeof param == 'undefined' || param == null) {
            return defaultValue;
        }
        return param;
    },

    encodetoJSON: function(obj) {
        var pad = function(n) {
            return n < 10 ? '0' + n : n;
        };

        var m = {
            '\b': '\\b',
            '\t': '\\t',
            '\n': '\\n',
            '\f': '\\f',
            '\r': '\\r',
            '"' : '\\"',
            '\\': '\\\\'
        };

        var encodeString = function(s) {
            if (/["\\\x00-\x1f]/.test(s)) {
                return '"' + s.replace(/([\x00-\x1f\\"])/g, function(a, b) {
                    var c = m[b];
                    if (c) {
                        return c;
                    }
                    c = b.charCodeAt();
                    return '\\u00' +
                           Math.floor(c / 16).toString(16) +
                           (c % 16).toString(16);
                }) + '"';
            }
            return '"' + s + '"';
        };

        var encodeArray = function(o) {
            var a = ['['], b, i, l = o.length, v;
            for (i = 0; i < l; i += 1) {
                v = o[i];
                switch (typeof v) {
                    case 'undefined':
                    case 'function':
                    case 'unknown':
                        break;
                    default:
                        if (b) {
                            a.push(',');
                        }
                        a.push(v === null ? "null" : _amzn_utils.encodetoJSON(v));
                        b = true;
                }
            }
            a.push(']');
            return a.join('');
        };

        var encodeDate = function(o) {
            return '"' + o.getFullYear() + '-' +
                   pad(o.getMonth() + 1) + '-' +
                   pad(o.getDate()) + 'T' +
                   pad(o.getHours()) + ':' +
                   pad(o.getMinutes()) + ':' +
                   pad(o.getSeconds()) + '"';
        };

        if (typeof obj == 'undefined' || obj === null) {
            return 'null';
        } else if (obj instanceof Array) {
            return encodeArray(obj);
        } else if (obj instanceof Date) {
            return encodeDate(obj);
        } else if (typeof obj == 'string') {
            return encodeString(obj);
        } else if (typeof obj == 'number') {
            return isFinite(obj) ? String(obj) : "null";
        } else if (typeof obj == 'boolean') {
            return String(obj);
        } else {
            var a = ['{'], b, v;
            for (var i in obj) {
                if (_amzn_utils.objHasOwnProperty(obj, i)) {
                    v = obj[i];
                    switch (typeof v) {
                        case 'undefined':
                        case 'function':
                        case 'unknown': break;
                        default:
                            if (b) {
                                a.push(',');
                            }
                            a.push(_amzn_utils.encodetoJSON(i), ':', v === null ? "null" : _amzn_utils.encodetoJSON(v));
                            b = true;
                    }
                }
            }
            a.push('}');
            return a.join('');
        }
    }
};

function initOnloadFunctions() {
    if (typeof(window.addEventListener) != 'undefined') {
        window.addEventListener('load', main, false);
    } else {
        var oldOnload = window.onload;
        var mainFuncPtr = main;
        window.onload = function () {
            if (typeof oldOnload == 'function') {
                oldOnload();
            }
            mainFuncPtr();
        };
    }
}

/************** STATIC JAVASCRIPT BEGIN ****************/
if (typeof amzn_wdgts_vars == 'undefined') {
    amzn_wdgts_vars = new Array();
}
if (typeof amzn_wdgt == 'undefined') {
    amzn_wdgt = {};
}
if (typeof amzn_wdgt.templateId == 'undefined') {
    amzn_wdgt.templateId = null;
}
if (typeof amzn_wdgt.marketPlace == 'undefined') {
    amzn_wdgt.marketPlace = 'US';
}
if (typeof amzn_wdgts_vars[amzn_wdgt.marketPlace] == 'undefined') {
    amzn_wdgts_vars[amzn_wdgt.marketPlace] = new Array();
}
if (typeof amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId] == 'undefined') {
    amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId] = new Array();
}
if (typeof amzn_wdgt.displayTemplate == 'undefined') {
    amzn_wdgt.displayTemplate = '1';
}

var instanceId = amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId].length;
var divId = 'amazon_widget_' + amzn_wdgt.marketPlace + '_' + amzn_wdgt.templateId + '_' + instanceId;
if (typeof amzn_wdgt.width == 'undefined') {
    amzn_wdgt.width = 0;
}

// set widgetserver variables if they have not been set
if (typeof amzn_wdgt.tag == 'undefined') {
    amzn_wdgt.tag = _amzn_utils.getString(_amzn_utils.DefaultTag, amzn_wdgt.marketPlace);
}
amzn_wdgt.refURL = escape(document.location).replace(/[+]/g,'%2B'); 
// additional replace to handle the + symbol. Javascript escape does not escape +, but apache decodes it to space
if (typeof wsPreview == 'undefined') {
     if (document.readyState != 'complete') {
         document.write('<div class=\'' + divId + '\' id=\'' + divId + '\'></div>'); 
     }
     if (!document.getElementById(divId)) {
       try {
         var divEl = document.createElement('div');
         divEl.id = divId;
         divEl.setAttribute('class', divId);
         document.getElementById('search_widget_preview_block').querySelectorAll('#preview_script')[0].appendChild(divEl);
       } catch(err) {
         // .querySelectorAll not supported on older browsers
       }
     }
} else {
    var displayDiv = document.createElement('div');
    displayDiv.id = 'amazon_widget_' + amzn_wdgt.marketPlace + '_' + amzn_wdgt.templateId + '_0';
    document.getElementById("preview_section_demo").appendChild(displayDiv);
}
amzn_wdgt.instanceId = instanceId;
amzn_wdgt.isTaken = false;
amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId].push(_amzn_utils.clone(amzn_wdgt));

var x = amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId][amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId].length - 1];
var startTimestamp = new Date().getTime();

var initUnloadFunction = function(widgetInstance, beginTime) {
    function amznWidgetsUnload(wdgtObject, loadTime) {
        if (typeof wdgtObject.hasLoaded == 'undefined') {
            var timeNow = new Date().getTime();
            var timeSpent = timeNow - loadTime;

            var img = document.createElement('IMG');
            img.style.width = '1px';
            img.style.height = '1px';
            img.style.border = 'none';
            img.src = _amzn_utils.imageDirectory(wdgtObject.marketPlace) + '/transparent-pixel.gif?'
                    + 'locale=' + wdgtObject.marketPlace
                    + '&tag=' + wdgtObject.tag
                    + '&templateId=' + wdgtObject.templateId
                    + '&instanceId=' + wdgtObject.instanceId
                    + '&ID=' + (typeof wdgtObject.ID != 'undefined'? wdgtObject.ID : "NOID")
                    + '&timeSpent=' + timeSpent
                    + '&serviceVersion=' + wdgtObject.serviceVersion;
            document.body.appendChild(img);
        }
    }

    if (typeof(window.addEventListener) != 'undefined') {
        window.addEventListener('unload', function() {
            amznWidgetsUnload(widgetInstance, beginTime);
        }, false);
    } else {
        var oldOnUnload = window.onunload;
        window.onunload = function () {
            if (typeof oldOnUnload == 'function') {
                oldOnUnload();
            }
            amznWidgetsUnload(widgetInstance, beginTime);
        };
    }
}
initUnloadFunction(x, startTimestamp);

if (typeof _amzn_popup == 'undefined') {
    if(typeof wsPreview == 'undefined' && document.readyState != 'complete'){
        document.writeln('<script src="'+ _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace) + '/js/popup.js" > </script>');
    } if (typeof _amzn_popup == 'undefined') {
        var popover = document.createElement('script');
        popover.src = _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace)+"/js/popup.js";
        document.body.appendChild(popover);
    }
}
if (!(typeof Nifty == 'function' && typeof NiftyCheck == 'function')) {
    if(typeof wsPreview == 'undefined' && document.readyState != 'complete'){
        document.writeln('<script src="'+ _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace) + '/js/nifty.js" > </script>');
    } if (!(typeof Nifty == 'function' && typeof NiftyCheck == 'function')) {
        var nifty = document.createElement('script');
        nifty.src = _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace)+"/js/nifty.js";
        document.body.appendChild(nifty);
    }
}
if (!(typeof Color == 'function' && typeof RGB == 'function')) {
    if(typeof wsPreview == 'undefined' && document.readyState != 'complete'){
        document.writeln('<script src="'+ _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace) + '/js/colors.js" > </script>');
    } if (!(typeof Color == 'function' && typeof RGB == 'function')) {
        var colors = document.createElement('script');
        colors.src = _amzn_utils.amznMediaserverURL(amzn_wdgt.marketPlace)+"/js/colors.js";
        document.body.appendChild(colors);
    }
}
/*************** STATIC JAVASCRIPT END *****************/
function main() {
    var wdgt = {
        _amzn_autocompletion_utils : {
            //Global variables
            curSelection : -1,  //the current selection index in the suggestion list
            curSuggestions : [], //array of suggestions returned from the server
            curSize : 0, //the number of suggestions displayed (can be less than the number returned from the server)
            curText : "", //the text that was currently entered in the search box
            curTextSel : "", //the text that is currently selected with up, down keys
            hideDelayTimerId : null, //timer id used to delay the hiding of the suggestions list
            searchSuggestionTimerId : null, //timer id used to delay the execution of a new search suggestion request
            maxSuggestions : 10, //maximum number of suggestions that will be displayed
            prevWndResizeEventHandler : null, //existing event handler
            prevWndOnLoadEventHandler : null,
            isMsie : false,
            suggestRequest : null,
            clientId : "client-associates-search", // client-id needed by A9
            suggestionsLoaded : false, //to prevent hooking the events twice
            suggestDiv : null,
            scriptCounter:1,
            suggestUrl:null,
            scriptObj:null,
            marketPlace: 'US',
            parentObject: null,
            sugdivIdPrefix: '_amzn_US_8002_0_sugdiv_',
            keyDownHandler: null,
            keyUpHandler: null,
            keyPressHandler: null,
            keyBlurHandler: null,

            detachEventListener: function (elemObj, eventType, eventHandler) {
                var eventName = "on" + eventType;
                if (elemObj.removeEventListener) {
                    elemObj.removeEventListener(eventType, eventHandler, false);
                } else if (elemObj.detachEvent) {
                    elemObj.detachEvent(eventName, eventHandler);
                } else {
                    elemObj[eventName] = null;
                }
            },

            attachEventListener: function (elemObj, eventType, eventHandler) {
                var eventName = "on" + eventType;
                if (elemObj.addEventListener) {
                    elemObj.addEventListener(eventType, eventHandler, false);
                } else if (elemObj.attachEvent) {
                    elemObj.attachEvent(eventName, eventHandler);
                } else {
                    elemObj[eventName] = function() {
                        return eventHandler.apply(this, arguments);
                    };
                }
            },

            initSearchSuggest: function(marketPlace, parentObject) {
                this.marketPlace = marketPlace;
                this.parentObject = parentObject;
                this.sugdivIdPrefix = '_amzn_' + marketPlace + '_8002_' + parentObject.instanceId + '_sugdiv_';

                this.isMsie = navigator.userAgent.toLowerCase().indexOf("msie") != -1;
                var searchBox = this.getSearchBox();
                if (searchBox) {
                    this.curText = searchBox.value;
                    searchBox.setAttribute("autocomplete", "off");

                    var self = this;

                    this.detachEventListener(searchBox, "keydown", this.keyDownHandler );
                    this.detachEventListener(searchBox, "keyup", this.keyUpHandler );
                    this.detachEventListener(searchBox, "keypress", this.keyPressHandler );
                    this.detachEventListener(searchBox, "blur", this.keyBlurHandler );

                    this.keyDownHandler = function (e) { return self.onKeyDownEvent(e,self); };
                    this.keyUpHandler = function(e) { return self.onKeyUpEvent(e, self); };
                    this.keyPressHandler = function(e) {return self.onKeyPressedEvent(e, self); };
                    this.keyBlurHandler = function(e) { return self.onFocusLost(e, self); };

                    this.attachEventListener(searchBox, "keydown", this.keyDownHandler );
                    this.attachEventListener(searchBox, "keyup", this.keyUpHandler );
                    this.attachEventListener(searchBox, "keypress", this.keyPressHandler );
                    this.attachEventListener(searchBox, "blur", this.keyBlurHandler );

                    this.prevWndResizeEventHandler = window.onresize; //save previous one
                    this.attachEventListener(window, "resize", function(e) { return self.onWindowResized(e, self); } );

                    this.suggestionsLoaded = true;

                    //This is needed for all IME languages as key events are not consistently generated
                    if (_amzn_utils.getString(_amzn_utils.issMktid, this.marketPlace) == 6) { //JP
                        window.setInterval(
                                function() {
                                    var val = searchBox.value;
                                    if (self == document.activeElement && val != self.curText && val != self.curTextSel) {
                                        self.curText = val;
				    	self.setSearchSuggestionTimeout();
                                    }
                                }, 20);
                    }
                }
            },

            supportedSearchAlias: function (alias) {
                return _amzn_utils_searchalias.getInlineSearchAliases(this.marketPlace)[alias];
            },

            onKeyDownEvent: function (event, self) {
                var key = event.keyCode;
                switch (key) {
                    case 40: self.moveDown();
                        self.stopEvent(event);
                        break;
                    case 38: self.moveUp();
                        self.stopEvent(event);
                        break;
                }
            },

            onKeyUpEvent: function (event, self) {
                var key = event.keyCode;
                switch (key) {
                    case 13: var suggestedKeyword = self.curSuggestions[self.curSelection];
                             if(typeof suggestedKeyword != 'undefined' && suggestedKeyword){
                                 self.getSearchBox().value = suggestedKeyword;
                             }
                             // In JP the Enter key might just come from IME commit so we dont hide the suggestions div
                             if (_amzn_utils.getString(_amzn_utils.issMktid, self.marketPlace) != 6) {
                                  self.HideSuggestionsDiv();
                             }
                             break;
                    case 40: break;
                    case 38: break;
                    case 37: break;//left arrow
                    case 39: break;//right arrow
                    default: {
                        var val = self.getSearchBox().value;
                        if (val != self.curText) {
                            self.curText = val;
                            self.setSearchSuggestionTimeout();
                        }
                    }
                        break;
                }
            },

            onKeyPressedEvent: function(event, self) {
                if (event.keyCode == 27 && self.getSearchSuggest().style.display != "none") {
                    self.setSuggestionHideTimeout();
                    return false;
                }
            },

            onFocusLost: function (event, self) {
                // The hiding is done with a delay, otherwise the click event is not received when a suggestion is clicked
                self.setSuggestionHideTimeout();
            },

            onWindowResized: function (event, self) {
                self.getSearchSuggest().style.width = self.getSearchBox().offsetWidth;
                if (self.prevWndResizeEventHandler) {
                    self.prevWndResizeEventHandler(event);
                }
            },

            displaySuggestions: function (curSuggestions) {
                try {
                    this.curSize = Math.min(this.maxSuggestions, curSuggestions.length);
                } catch(e) {
                    this.curSize = 0;
                }

                var ss = this.getSearchSuggest();
                ss.innerHTML = '';
                if (this.curSize > 0) {
                    ss.style.display = "";
                } else {
                    this.HideSuggestionsDiv();
                }

                var mktPlace = this.parentObject.marketPlace;
                var templateId = this.parentObject.templateId;
                var instanceId = this.parentObject.instanceId;

                window.nextCallBack[mktPlace][templateId][instanceId]['suggestOver'] = this.suggestOver;
                window.nextCallBack[mktPlace][templateId][instanceId]['suggestOut'] = this.suggestOut;
                window.nextCallBack[mktPlace][templateId][instanceId]['setSearch'] = this.setSearch;

                //This isnt done with DOM as some IE versions do not support dynamically added attributes.
                for (var i = 0; i < this.curSize; ++i) {
                    var divId = '_amzn_' + mktPlace + '_8002_' + instanceId + '_sugdiv_' + i;
                    var suggest = '<div id="' + divId + '" onmouseover="javascript:' +
                                  'window.nextCallBack' +
                                  '[\'' + mktPlace + '\']' +
                                  '[' + templateId + ']' +
                                  '[' + instanceId + ']' +
                                  '.suggestOver(\'' + mktPlace + '\', ' + templateId + ', ' + instanceId + ',\'' + divId + '\', ' + i + ')"';

                    suggest += ' onmouseout="javascript:' +
                                  'window.nextCallBack' +
                                  '[\'' + mktPlace + '\']' +
                                  '[' + templateId + ']' +
                                  '[' + instanceId + ']' +
                                  '.suggestOut(\'' + mktPlace + '\', ' + templateId + ', ' + instanceId + ',\'' + divId + '\')"';

                    suggest += ' onclick="javascript:' +
                                  'window.nextCallBack' +
                                  '[\'' + mktPlace + '\']' +
                                  '[' + templateId + ']' +
                                  '[' + instanceId + ']' +
                                  '.setSearch(\'' + mktPlace + '\', ' + templateId + ', ' + instanceId + ')" ';

                    suggest += ' style="font-size:10px; font-family: Verdana; width:'
                            + this.getSearchSuggest().style.offsetWidth + 'px;padding: 2px 6px 2px 6px;" class="suggest_link">'
                            + this.getFormatedSuggestionLine(curSuggestions[i]) + '</div>';
                    ss.innerHTML += suggest;
                }
            },

            //Mouse over function
            suggestOver: function (_mktPlace, _templateId, _instanceId, _divId, _curSelection) {
                var self = all_amzn_wdgts[_mktPlace][_templateId][_instanceId];
                var div = _amzn_utils.$(_divId);

                div.style.cursor = "default";
                self._amzn_autocompletion_utils.curSelection = _curSelection;

                self._amzn_autocompletion_utils.unhighlightCurrentSuggestion();
                self._amzn_autocompletion_utils.highlightCurrentSuggestion();
            },

            //Mouse out function
            suggestOut: function (_mktPlace, _templateId, _instanceId, _divId) {
                var self = all_amzn_wdgts[_mktPlace][_templateId][_instanceId];
                var div = _amzn_utils.$(_divId);

                self._amzn_autocompletion_utils.unhighlightSuggestion(div);
            },

            setSearch: function (_mktPlace, _templateId, _instanceId) {
                var self = all_amzn_wdgts[_mktPlace][_templateId][_instanceId]._amzn_autocompletion_utils;
                self.curTextSel = self.curSuggestions[self.curSelection];
                self.getSearchBox().value = self.curSuggestions[self.curSelection];
                self.setSuggestionHideTimeout();
            },

            highlightSuggestion: function (div_value) {
                div_value.className = 'suggest_link_over';
                div_value.style.backgroundColor = '#146EB4';
            },

            unhighlightSuggestion: function (div_value) {
                div_value.className = 'suggest_link';
                div_value.style.backgroundColor = '#FFFFFF';
            },

            highlightCurrentSuggestion: function () {
                var selection = document.getElementById(this.sugdivIdPrefix + this.curSelection);
                this.highlightSuggestion(selection);
            },

            unhighlightCurrentSuggestion: function () {
                var selection = null;
                try {
                    selection = document.getElementById(this.sugdivIdPrefix + this.curSelection);
                } catch(e) {
                }

                if (selection) {
                    this.unhighlightSuggestion(selection);
                }
            },

            moveDown: function () {
                if (this.curSize <= 0) return;
                try {
                    this.unhighlightCurrentSuggestion();

                    if (this.curSelection >= this.curSize - 1) {
                        this.curSelection = -1;
                    } else {
                        ++this.curSelection;
                    }

                    this.highlightCurrentSuggestion(true);
                } catch(ex) {
                }
            },

            moveUp: function () {
                if (this.curSize <= 0) return;
                try {
                    this.unhighlightCurrentSuggestion();

                    if (this.curSelection < 0) {
                        this.curSelection = this.curSize - 1;
                    } else {
                        --this.curSelection;
                    }

                    this.highlightCurrentSuggestion();
                } catch(ex) {
                }
            },

            stopEvent: function(event) {
                if (this.isMsie) {
                    event.cancelBubble = true;
                } else {
                    event.preventDefault();
                }
            },

            getFormatedSuggestionLine: function (curSuggestion) {
                var lowercaseCurrentText = this.curText.toLowerCase();
                var lowercaseCurrentSuggestion = curSuggestion.toLowerCase();
                var len = this.curText.length;
                var start = lowercaseCurrentSuggestion.indexOf(lowercaseCurrentText);
                if (start == -1) {
                    return curSuggestion;
                }

                return curSuggestion.substr(0, start) + "<b>" + curSuggestion.substr(start, len) + "</b>" + curSuggestion.substr(start + len);
            },

            getSearchBox: function () {
                var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_8002_' + this.parentObject.instanceId);
                return _amzn_utils.getById('amzn_search_textfield', widget_div);
            },

            //This is created lazily. Make sure you always use the getter.
            getSearchSuggest: function () {
                if (!this.suggestDiv) {
                    this.suggestDiv = this.createSuggestionDiv(this.getSearchBox());
                }
                return this.suggestDiv;
            },

            getSearchAlias: function () {
                var widget_div = _amzn_utils.$('amazon_widget_' + this.marketPlace + '_8002_' + this.parentObject.instanceId);
                var searchTerms = _amzn_utils.getById('amzn_search_textfield', widget_div);

                if (!searchTerms.value) {
                    return null;
                }

                var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
                var lbel = searchDiv.textContent;
                if (typeof lbel == 'undefined' || lbel == null) {
                    lbel = searchDiv.childNodes[0].nodeValue;
                }
                var searchCategoryValue = this.parentObject.categoryValueFromLabel(lbel);
                return searchCategoryValue ? searchCategoryValue : null;
            },

            findPos: function (obj) {
                var origObj = obj;
                var curleft = 0;
                var curtop = 0;
                if (obj.offsetParent) {
                    do {
                        curleft += obj.offsetLeft;
                        curtop += obj.offsetTop;
                    } while (obj = obj.offsetParent);
                }

                var parentEl = origObj.parentNode;
                while (parentEl != null && parentEl != document.body) {
                    if (parentEl.scrollLeft) {
                        curleft -= parentEl.scrollLeft;
                    }
                    if (parentEl.scrollTop) {
                        curtop -= parentEl.scrollTop;
                    }
                    parentEl = parentEl.parentNode;
                }

                return [curleft,curtop];
            },

            createSuggestionDiv: function (parent) {
                var suggestionDiv = document.createElement("div");
                suggestionDiv.style.border = "1px solid black";
                suggestionDiv.style.position = "absolute";
                suggestionDiv.style.backgroundColor = "white";
                suggestionDiv.style.color = "black";

                var parentPos = this.findPos(parent);
                suggestionDiv.style.left = parentPos[0] + 'px';
                suggestionDiv.style.top = (parentPos[1] + parent.offsetHeight) + 'px';
                suggestionDiv.style.width = parent.offsetWidth + 'px';
                suggestionDiv.style.zIndex = "130";
                suggestionDiv.style.display = "none";
                suggestionDiv.id = "search_suggest";
                document.body.appendChild(suggestionDiv);

                return suggestionDiv;
            },

            setSuggestionHideTimeout: function () {
				var self = this;
                this.hideDelayTimerId = setTimeout(function() {
                    return (function() {
                        self.hideDelayTimerId = null;
                        self.HideSuggestionsDiv();
                    });
                }(), 300);
            },

            setSearchSuggestionTimeout: function () {
                if (this.searchSuggestionTimerId) {
                    clearTimeout(this.searchSuggestionTimerId);
                    this.searchSuggestionTimerId = null;
                }
				var self = this;
                this.searchSuggestionTimerId = setTimeout(function() {
                    return (function() {
                        self.searchJSONSuggest();
                        self.searchSuggestionTimerId = null;
                        self.curSelection = -1;
                    });
                }(), 100);
            },

            HideSuggestionsDiv: function () {
                this.curSize = 0;
                this.getSearchSuggest().innerHTML = '';
                this.getSearchSuggest().style.display = "none";
                this.curSelection = -1;
            },

            //Called from keyup on the search textbox.
            //Starts the AJAX request.
            searchJSONSuggest: function () {
                if (this.suggestRequest) {
                    this.removeScriptTag();
                }

                var searchAlias = this.getSearchAlias();
                if (! this.supportedSearchAlias(searchAlias)) {
                    return; //save the service call since no suggestions will be forthcoming
                }
                searchAlias = this.supportedSearchAlias(searchAlias);
                this.curText = this.getSearchBox().value;
                if (this.curText.length == 0) {
                    this.HideSuggestionsDiv();
                    return;
                }
                var str = encodeURIComponent(this.curText);

                this.suggestUrl = window.parent.document.location.protocol + '//' +
                                  _amzn_utils.getString(_amzn_utils.CompletionVIP, this.marketPlace) +
                                 '?' + 'method=completion' +
                                 '&q=' + str +
                                 '&search-alias=' + searchAlias +
                                 '&client=' + this.clientId +
                                 '&mkt=' + _amzn_utils.getString(_amzn_utils.issMktid, this.marketPlace) +
                                 '&x=_amzn_wdgt_8002_updateCompletionCallback';

                _amzn_wdgt_8002_updateCompletionHandler = this;
                this.suggestRequest = this.getScriptTag();
                this.addScriptTag();
            },

            //JSON callback. This is called by the JSON response
            updateCompletion: function (completions) {
                if (this.suggestRequest) {
                    this.removeScriptTag();
                    this.suggestRequest = null;
                }
                this.curSuggestions = completions;
                this.displaySuggestions(this.curSuggestions);
            },

            getScriptTag : function () {
                if (this.scriptObj) return this.scriptObj;

                // Keep IE from caching requests
                var noCacheIE = '&noCacheIE=' + (new Date()).getTime();
                var scriptId = 'JscriptId' + this.scriptCounter++;

                this.scriptObj = document.createElement("script");
                this.scriptObj.setAttribute("type", "text/javascript");
                this.scriptObj.setAttribute("charset", "utf-8");
                this.scriptObj.setAttribute("src", this.suggestUrl + noCacheIE);
                this.scriptObj.setAttribute("id", scriptId);

                return this.scriptObj;
            },

            removeScriptTag : function() {
                if (this.scriptObj) {
                    try {
                        document.getElementsByTagName("head").item(0).removeChild(this.scriptObj);
                        this.scriptObj = null;
                    } catch(e) {
                    }
                }
            },

            addScriptTag : function() {
                if (this.scriptObj) {
                    document.getElementsByTagName("head").item(0).appendChild(this.scriptObj);
                }
            }
        },

        validateRowsAndColumns: function() {
            if (this.isIAB) {
                var numberOfCols = this.width / 120.0;
                this.cols = Math.floor(numberOfCols);
            }
            if (this.cols * 120 > this.width) {
                this.cols = Math.floor(this.width / 120);
            }
        },

        createOptionTag:function(value, name, isSelected) {
            return isSelected
                   ? '<option value=\'' + value + '\' selected>' + name + '</option>'
                   : '<option value=\'' + value + '\'>' + name + '</option>';
        },

        getReviewImage: function(reviewRating) {
            return _amzn_utils.getRatingImage(reviewRating, this.marketPlace);
        },

        trimCharsByWidth: function(text, fontType, width, numOfLines) {
            return _amzn_utils.trimCharsByWidth(text, fontType, width, numOfLines, this);
        },


        pageNumberDiv: function(pageNumber, isCurrentPage, displayPageNumber) {
            return _amzn_utils.pageNumberDiv(pageNumber, isCurrentPage, this, displayPageNumber);
        },

        getEndPage: function () {
            var numberOfPages = this.getNumPages();
            var res = this.navBarBeginPage + this.resultWindowSize - 1;
            if (res > numberOfPages) {
                res = numberOfPages;
            }
            return res;
        },

        // 0 based index
        // It returns the item if it was already fetched,
        // returns false if it will start fetching now
        // and returns null if none was found (i.e. there aren't as many results for the search term).
        getItem: function (index) {
            var item = null;
            var currSearchPage = Math.ceil((index + 1)/this.requestSize);
            if (index + 1 > this.totalNumOfResults) {
                return null;
            }
            var itemArray = this.resultData[currSearchPage];
            if (itemArray == null) {
                item = false;
                this.goOnClick(this.marketPlace, this.instanceId, false);
            } else {
                item = itemArray[index % this.requestSize];
            }
            return item;
        },

        getItemsForPage: function () {
            var result = new Array();
            var itemsToBeSkippedUntil = (this.currentPage - 1) * this.totalItemsPerPage;
            var itemsToBeSkippedFrom = (this.currentPage) * this.totalItemsPerPage;
            if(itemsToBeSkippedFrom>= this.totalNumOfResults){
                itemsToBeSkippedFrom=this.totalNumOfResults;
            }
            for (var i = itemsToBeSkippedUntil; i < itemsToBeSkippedFrom; i++) {
                var item = this.getItem(i);
                if (item != null) {
                    result.push(item);
                } else if (item == null) {
                    return result;
                } else if (!item) {
                    return null;
                }
            }
            return result;
        },

        amazon_generate_widgets_url: function (operation, category, keyword) {
            if (operation == 'GetTopSellers') {
                var url = _amzn_utils.widgetServerURL(this.marketPlace) + '/q?'
                        + 'Operation=' + operation
                        + '&URL=' + this.refURL
                        + '&InstanceId=' + this.instanceId
                        + '&ResponseCount=' + this.totalItemsPerPage
                        + '&TemplateId=' + this.templateId
                        + '&ServiceVersion=' + this.serviceVersion
                        + '&MarketPlace=' + this.marketPlace;
                if (this.category && this.category != 'All') {
                    url += '&CategoryRestriction=' + this.category;
                }
                return url;
            } else {
                var indexOfFirstItemOnPage = (this.currentPage - 1) * this.totalItemsPerPage;
                var indexOfLastItemOnPage = (this.currentPage) * this.totalItemsPerPage - 1;

                if (this.totalNumOfResults != null && indexOfLastItemOnPage >= this.totalNumOfResults){
                    indexOfLastItemOnPage = this.totalNumOfResults;
                }

                function temp_getItem(index, self) {
                    var result = null;
                    var data = self.resultData;
                    if (data && data[Math.ceil((index + 1) / self.requestSize)]) {
                        result = data[Math.ceil((index + 1) / self.requestSize)][index % self.requestSize];
                    }
                    return result;
                }

                var firstItem = temp_getItem(indexOfFirstItemOnPage, this);
                var lastItem = temp_getItem(indexOfLastItemOnPage, this);

                if (firstItem == null) {
                    this.currentSearchPage = Math.floor(indexOfFirstItemOnPage / this.requestSize) + 1;
                } else if (lastItem == null) {
                    this.currentSearchPage = Math.floor(indexOfLastItemOnPage / this.requestSize) + 1;
                }

                var multipageStart = (this.currentSearchPage - 1) * this.requestSize;

                var multipageCount = this.requestSize;
                if (this.totalNumOfResults != null && multipageStart + multipageCount > this.totalNumOfResults) {
                    multipageCount = this.totalNumOfResults - multipageStart;
                }
                if (multipageCount < 0) {
                    multipageCount = 0;
                }

                return  _amzn_utils.widgetServerURL(this.marketPlace) + '/q?'
                        + 'Operation=' + operation
                        + '&Keywords=' + encodeURIComponent(keyword)
                        + '&SearchIndex=' + encodeURIComponent(category)
                        + '&multipageStart=' + multipageStart
                        + '&InstanceId=' + this.instanceId
                        + '&multipageCount=' + multipageCount
                        + '&TemplateId=' + this.templateId
                        + '&ServiceVersion=' + this.serviceVersion
                        + '&MarketPlace='+this.marketPlace;
            }
        },

        getBlankLayout : function() {
            this.setFixedHeightAttributes();
            var res = '';
            for (var i = 0; i < this.rows; i++) {
                for (var j = 0; j < this.cols; j++) {
                    res += this.getBlankTile();
                }
            }
            return res;
        },

        getErrorMsgBlankLayout : function() {
            if(this.width < 250 ) {
                this.setFixedHeightAttributes(100);
            } else {
                this.setFixedHeightAttributes(60);
            }
            var res = '';
            for (var i = 0; i < this.rows; i++) {
                for (var j = 0; j < this.cols; j++) {
                    res += this.getBlankTile();
                }
            }
            return res;
        },

        getMsgBlankLayout : function() {
            var res = '';
            for (var i = 0; i < this.rows && i < 1; i++) {
                for (var j = 0; j < this.cols; j++) {
                    res += this.getBlankTile();
                }
            }
            return res;
        },

        getSearchingLayout : function() {
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var wdgt_brdr = _amzn_utils.getById('wdgt_brdr', widget_div);
            this.isSearchCallback = this.currentPage != 1;
            this.setWdgtBrdrHeight();
            var ht = wdgt_brdr.clientHeight - 8.5;
            var topDiv = (Math.floor((ht - 58) / 2)) + 'px';
            var text = this.currentPage == 1 ? _amzn_utils.Searching : _amzn_utils.Loading;
            text = _amzn_utils.getString(text, this.marketPlace);
            return '<div align=\'center\' style=\'width:' + this.innerWidth + 'px;height:' + ht + 'px;\'>'
                   + '<div class=\'message\' id=\'searching\' style=\'background-image: url("' + _amzn_utils.imageDirectory(this.marketPlace) + '/round.gif");position: relative;top:' + topDiv + ';color:black;text-align:center;height: 59px;width: 100px;font:10px Verdana;\'>'
                   + '<div class=\'messagetext\' align=\'center\' style=\'position: relative;top:17px;\'><img style=\'position:relative;top:4px;border:none;margin:0;\' src=\'' + _amzn_utils.imageDirectory(this.marketPlace) + '/loading-spinner.gif\'/>&nbsp;&nbsp;' + text + '...'
                   + '</div>'
                   + '</div>'
                   + '</div>';
        },

        getShowString: function(startIndex, endIndex, totalResults, searchTerm, category, width) {
            if (width <= 150) {
                var ofString;
                switch (this.marketPlace) {
                    case 'DE': ofString = 'von'; break;
                    case 'FR': ofString = 'de'; break;
                    case 'JP': ofString = 'の'; break;
                    default: ofString = 'of'; break;
                }
                var result = [];
                result.push(' '); // normal
                result.push(startIndex + ' - ' + endIndex + ' '); // bold
                result.push(' ' + ofString + ' '); // normal
                result.push(totalResults); // bold
                return result;
            } else {
                var result = [];
                switch (this.marketPlace) {
                    case 'DE':
                        result.push(' '); // normal
                        result.push(startIndex + ' - ' + endIndex + ' '); // bold
                        result.push('von '); // normal
                        result.push(totalResults + ' '); // bold
                        result.push(' Ergebnissen'); // normal
                        break;

                    case 'FR':
                        result.push('Résultats '); // normal
                        result.push(startIndex + ' - ' + endIndex + ' '); // bold
                        result.push(' sur '); // normal
                        result.push(totalResults + ' '); // bold
                        break;

                    case 'JP':
                        result.push('検索結果'); // normal
                        result.push(totalResults); // bold
                        result.push("件中"); // normal
                        result.push(startIndex); // bold
                        result.push('件から'); // normal
                        result.push(endIndex); // bold
                        result.push('件までを表示'); // normal
                        break;

                    default:
                        result.push('Showing '); // normal
                        result.push(startIndex + ' - ' + endIndex + ' '); // bold
                        result.push(' of '); // normal
                        result.push(totalResults + ' '); // bold
                        result.push(' results'); // normal
                        break;
                }
                return result;
            }
        },

        addResult: function () {
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var parentnode = _amzn_utils.getById('wdgt_brdr', widget_div);

            var itemsInPage = this.getItemsForPage();
            if (itemsInPage == null || this.searchInProgress) {
                return;
            }

            var firstItem = (this.currentPage - 1) * this.totalItemsPerPage + 1;
            var lastItem = firstItem + itemsInPage.length - 1;

            var correctedQueryStr = '';
            var sTerm = this.searchTerms;
            if (this.correctedQuery && this.correctedQuery.length > 0) {
                if (this.marketPlace == 'JP') {
                    correctedQueryStr = this.getSplitTitle([' ', _amzn_utils.escapeHTML(this.searchTerms), _amzn_utils.escapeHTML(_amzn_utils.getString(_amzn_utils.NoResultsFor, this.marketPlace))]);
                } else {
                    correctedQueryStr = this.getSplitTitle([_amzn_utils.escapeHTML(_amzn_utils.getString(_amzn_utils.NoResultsFor, this.marketPlace)), _amzn_utils.escapeHTML(this.searchTerms)]);
                }
                sTerm = this.correctedQuery;
            }

            var searchMsgPadding = "padding:0 9px 9px 9px;"
            var searchMsgWidth = this.innerWidth - 30;
            if(this.isIAB) {
                searchMsgPadding = "padding:0 9px 3px 9px;"
                if(_amzn_utils.amzn_isMSIE()) {
                    searchMsgPadding = "padding:0 0px 3px 9px;"
                    searchMsgWidth = this.innerWidth - 10;
                }
            }
            var res = '<div style=\'width:' + searchMsgWidth + 'px;' + searchMsgPadding + 'text-align:left;font-family: Verdana, sans-serif; font-size: 10px;'+this.style_tile_h1()+'\'>'

            var line2 = this.getShowString(firstItem, lastItem, this.totalNumOfResults, sTerm, this.searchCategory, this.width);
            res += this.getSplitTitle(line2);
            res += '</div>';

            var count = 0;
            for (var i in itemsInPage) {
                if (_amzn_utils.objHasOwnProperty(itemsInPage, i)) {
                    res += this.getTile(itemsInPage[i]);
                    count++;
                }
            }
            for (var i = 0; i < (this.cols * this.rows) - count; i++) {
                res += this.getBlankTile();
            }

            parentnode.innerHTML = res;
            _amzn_utils.runPNGTransparencyHack(widget_div, this.marketPlace);
            _amzn_utils.runPNGTransparencyHackForBkgdImage(_amzn_utils.getById('wdgt_brdr', widget_div));

            var navBarNode = _amzn_utils.getById('nav', widget_div);
            navBarNode.style.height = null;
            navBarNode.innerHTML = this.drawNavBar();
            if(this.isIAB && _amzn_utils.amzn_isMSIE() && !this.isNavbarShown) {
                this.clearNavBar();
            }
        },

        clearNavBar: function () {
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var navBarNode = _amzn_utils.getById('nav', widget_div);
            navBarNode.innerHTML = '<div class=\'pgn_cnt\'></div>';
            navBarNode.style.height = '0px';
        },

        selectCategoryFromDropdown: function(category, instanceID, templateID, marketPlace) {
            var self = all_amzn_wdgts[marketPlace]['8002'][instanceID];
            self.selectCategory(category);
            _amzn_popup.hideNow();
        },

        createAllDivs: function() {
            var res = '';
            for (var value in this.valueToLabel) {
                if (_amzn_utils.objHasOwnProperty(this.valueToLabel, value)) {
                    var lbel = this.valueToLabel[value];
                    res += this.createDiv(lbel, value);
                }
            }
            return res;
        },

        createDiv: function(lbel, value) {
            return '<div style=\'cursor:pointer;text-decoration: none;padding:2px;font: 100% Verdana, Arial, Helvetica, sans-serif;'
                    + 'font-size: 9px;text-align: left;\' '
                    + 'id = "selectedCategoryDiv_value_'+value+'" '
                    + 'onclick=\'javascript:window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].'
                    + 'selectCategoryFromDropdown("' + value + '",' + this.instanceId + ',' + this.templateId + ',"' + this.marketPlace + '");\' '
                    + 'onmouseover=\'if(!window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].isCategorySelected("'+value+'","'+this.templateId+'","'+this.instanceId+'","'+this.marketPlace+'"))this.style.backgroundColor="#e3e3e3";\' '
                    + 'onmouseout=\'if(!window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].isCategorySelected("'+value+'","'+this.templateId+'","'+this.instanceId+'","'+this.marketPlace+'"))this.style.backgroundColor="#ffffff";\' >' + lbel + '</div>';
        },

        highlightSelectedCategory: function (marketPlace, templateId, instanceId){
            var self = all_amzn_wdgts[marketPlace][templateId][instanceId];
            var widget_div = _amzn_utils.$('amazon_widget_'+ self.marketPlace + '_' + self.templateId + '_' + self.instanceId);
            var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
            var lbel = searchDiv.textContent;
            if (typeof lbel == 'undefined' || lbel == null) {
                lbel = searchDiv.childNodes[0].nodeValue;
            }
            var searchCategoryValue = self.categoryValueFromLabel(lbel);
            for(var v in self.valueToLabel){
                if (_amzn_utils.objHasOwnProperty(self.valueToLabel,v)) {
                    var valueId = _amzn_utils.byId('selectedCategoryDiv_value_' + v, document);
                    if (v == searchCategoryValue) {
                        valueId.style.backgroundColor = '#666666';
                        valueId.style.color = '#ffffff';
                    } else {
                        valueId.style.backgroundColor = '#ffffff';
                        valueId.style.color = '#000000';
                    }
                }
            }
        },

        isCategorySelected: function(category, templateId, instanceId, marketPlace){
            var self = all_amzn_wdgts[marketPlace][templateId][instanceId];
            var widget_div = _amzn_utils.$('amazon_widget_'+ self.marketPlace + '_' + self.templateId + '_' + self.instanceId);
            var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
            var lbel = searchDiv.textContent;
            if (typeof lbel == 'undefined' || lbel == null) {
                lbel = searchDiv.childNodes[0].nodeValue;
            }
            var searchCategoryValue = self.categoryValueFromLabel(lbel);
            return(searchCategoryValue==category);
        },

        createSearchSelectbox: function () {
            if(!window.nextCallBack){
                window.nextCallBack = new Object();
            }
            if (!window.nextCallBack[this.marketPlace]) {
                window.nextCallBack[this.marketPlace] = new Object();
            }
            if (!window.nextCallBack[this.marketPlace][this.templateId]) {
                window.nextCallBack[this.marketPlace][this.templateId] = new Object();
            }
            if(!window.nextCallBack[this.marketPlace][this.templateId][this.instanceId]) {
                window.nextCallBack[this.marketPlace][this.templateId][this.instanceId] = new Object();
            }
            window.nextCallBack[this.marketPlace][this.templateId][this.instanceId].selectCategoryFromDropdown = this.selectCategoryFromDropdown;

            var ht = 250;
            switch (this.marketPlace) {
                case 'CA': ht = 100; break;
                case 'DE': ht = 150; break;
                case 'FR': ht = 150; break;
                case 'GB': ht = 200; break;
                case 'JP': ht = 200; break;
                case 'US': ht = 250; break;
            }

            var popUp = escape('<div style=\'background-color:#FFFFFF;border: 1px solid #000000;width:140px;height:' + ht + 'px;overflow:auto;\'>'
                    + this.createAllDivs() + '</div>');
            window.nextCallBack[this.marketPlace][this.templateId][this.instanceId].isCategorySelected = this.isCategorySelected;
            window.nextCallBack[this.marketPlace][this.templateId][this.instanceId].highlightSelectedCategory=this.highlightSelectedCategory;
            return '<span style=\'white-space:nowrap;border: 1px solid;cursor:pointer;\''
                    + ' onmouseover=\'_a=this; _amzn_popup.showpreview("'+ popUp +'", _a, event,50);'
                    + 'window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].highlightSelectedCategory("'+this.marketPlace+'","'+this.templateId+'","'+this.instanceId+'");\' '
                    + 'onmouseout=\'_amzn_popup.hide()\''
                    + '><span id=\'selectedCategoryDiv\'>'
                    + this.getTrimmedCategory(this.valueToLabel[this.defaultSearchCategoryValue]) + '</span>'
                    + '<img id=\'selectCategoryImg\' style=\'vertical-align:middle;padding:0 0 0 1px;border:none;margin:0;\' src=\''
                    + _amzn_utils.imageDirectory(this.marketPlace) + '/ddwn_tpng.png\' width=\'11\' height=\'11\' '
                    + '/></span>';
        },

        resetAllVariables: function () {
            this.resultData = new Array();
            this.totalNumOfResults = null; // this will be assigned the total number of search results in the display_callback function.

            this.resultWindowSize = 5;
            this.totalItemsPerPage = this.getTotalItemsPerPage();
            this.currentPage = 1;
            this.currentSearchPage = 1;
            this.navBarBeginPage = 1;
            this.navBarEndPage = this.navBarBeginPage + this.resultWindowSize - 1;
            this.requestSize = this.totalItemsPerPage > 10 ? this.totalItemsPerPage : 10;
        },

        MAX_CHARS: 7,

        getTrimmedCategory:function(str) {
            if (str && str.length > this.MAX_CHARS) {
                return str.substr(0, this.MAX_CHARS) + "&hellip;";
            }
            return str;
        },

        selectCategory: function(selectedCategory) {
            if (!this.categoryFixed) {
                var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
                var cat = _amzn_utils.getById('selectedCategoryDiv', widget_div);
                var selectedCatlabel = this.valueToLabel[selectedCategory];
                if (selectedCatlabel && selectedCatlabel.length > this.MAX_CHARS) {
                    selectedCatlabel = selectedCatlabel.substr(0, this.MAX_CHARS) + "&hellip;";
                }
                cat.innerHTML = selectedCatlabel;
            }
        },

        categoryValueFromLabel: function(lbel) {
            for (var value in this.valueToLabel) {
                if (_amzn_utils.objHasOwnProperty(this.valueToLabel,value)) {
                    var newLabel = this.valueToLabel[value];
                    if ((newLabel == lbel) || (newLabel.length > this.MAX_CHARS
                            && lbel.length > this.MAX_CHARS
                            && newLabel.substr(0, this.MAX_CHARS) == lbel.substr(0, this.MAX_CHARS))) {
                        return value;
                    }
                }
            }
            return 'All';
        },

        goOnClick: function(marketPlace, instanceID, isNewSearch) {
            var self = all_amzn_wdgts[marketPlace]['8002'][instanceID];
            if (self.searchInProgress) return;
            var widget_div = _amzn_utils.$('amazon_widget_'+ self.marketPlace + '_' + self.templateId + '_' + self.instanceId);
            var searchTerms = _amzn_utils.getById('amzn_search_textfield', widget_div);
            if (self._amzn_autocompletion_utils.getSearchSuggest().style.display != 'none') {
		if(self._amzn_autocompletion_utils.curSelection > -1){
			var selKeyword = self._amzn_autocompletion_utils.curSuggestions[self._amzn_autocompletion_utils.curSelection];
			if(typeof(selKeyword) != "undefined" && selKeyword){
				searchTerms.value = selKeyword;
			}
		}
                self._amzn_autocompletion_utils.setSuggestionHideTimeout();
            }


            if (!searchTerms.value && (typeof isNewSearch == 'undefined' || isNewSearch)) {
                return;
            }

            var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
            var lbel = searchDiv.textContent;
            if (typeof lbel == 'undefined' || lbel == null) {
                lbel = searchDiv.childNodes[0].nodeValue;
            }
            var searchCategoryValue = self.categoryValueFromLabel(lbel);

            if (typeof isNewSearch == 'undefined' || isNewSearch) {
                self.searchTerms = searchTerms.value;
                self.searchCategory = searchCategoryValue;
            } else {
                searchTerms.value = self.searchTerms;
                self.selectCategory(self.searchCategory);
                searchCategoryValue = self.searchCategory;
            }
            self.disableSearchFields(true);
            self.searchInProgressID = setTimeout(function() {
                if (self.searchInProgress) {
                    var parentnode = _amzn_utils.getById('wdgt_brdr', widget_div);
                    /*parentnode.innerHTML = '<div style=\'width:' + (self.innerWidth - 30) + 'px;padding:9px 2px 9px 2px;font-family: Verdana, sans-serif; font-weight:bold; font-size: 10px;'+self.style_tile_h1()+'\'>'
                            + _amzn_utils.getString(_amzn_utils.ErrorMessage, self.marketPlace)
                            + '</div>'
                            + self.getErrorMsgBlankLayout();*/
                    self.disableSearchFields(false);
                }
            }, 30000);

            if (typeof isNewSearch == 'undefined' || isNewSearch) {
                self.resetAllVariables();
                self.clearNavBar();
            }

            self.search(searchTerms.value, searchCategoryValue);
        },

        topseller_display_callback: function(topsellers) {
            if(typeof topsellers == 'undefined' || topsellers == null ) {
                topsellers = new Array();
            }
            this.topsellers = topsellers;
            var res = '';
            this.mergeTemplate();
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var parentnode = _amzn_utils.getById('wdgt_brdr', widget_div);
            this.setFixedHeightAttributes();
            var count = 0;
            for (var i = 0; i < topsellers.length && i < this.totalItemsPerPage; i++, count++) {
                res += this.getTile(topsellers[i]);
            }

            for (var i = 0; i < (this.cols * this.rows) - count; i++) {
                res += this.getBlankTile();
            }
            parentnode.innerHTML = res;
            _amzn_utils.runPNGTransparencyHack(widget_div, this.marketPlace);
            _amzn_utils.runPNGTransparencyHackForBkgdImage(_amzn_utils.getById('wdgt_brdr', widget_div));
            if (typeof loadComplete == 'function') {
                loadComplete("topseller");
            }
            this.setWdgtBrdrHeight();
        },

        curveCorners: function() {
            Nifty('div#amzn_wdgt_t_8002_' + this.instanceId, 'transparent' + this.curveTheseCorners);
        },

        callDefaultSearchWebService: function() {
            this.topseller_display_callback(new Array());
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            _amzn_utils.getById('amzn_search_textfield', widget_div).value = this.defaultSearchTerm;
            this.goOnClick(this.marketPlace, this.instanceId, true);
        },

        handleDefaultSearchTerm: function(widgetData) {
            setTimeout(function() {
                if (typeof _amzn_popup == 'object' && typeof Nifty =='function') {
                    all_amzn_wdgts[widgetData.MarketPlace]['8002'][widgetData.InstanceId].callDefaultSearchWebService();
                } else {
                    all_amzn_wdgts[widgetData.MarketPlace]['8002'][widgetData.InstanceId].handleDefaultSearchTerm(widgetData);
                }
            }, 50);
        },

        callWebService: function() {
            if(this.useDefaultSearchTerm && this.defaultSearchTerm && this.defaultSearchTerm != "") {
                var topsellerDataObject = { };
                topsellerDataObject.results = [];
                topsellerDataObject.MarketPlace = this.marketPlace,
                topsellerDataObject.InstanceId = this.instanceId;
                this.handleDefaultSearchTerm(topsellerDataObject);
            } else {
                var res = document.createElement('script');
                res.charset = 'utf-8';
                res.src = this.amazon_generate_widgets_url('GetTopSellers');
                document.body.appendChild(res);
            }
        },

        search: function(keyword, category) {
            var res = document.createElement('script');
            res.charset = 'utf-8';
            res.src = this.amazon_generate_widgets_url('GetResults', category, keyword);
            document.body.appendChild(res);
            this.addWait('wait');
        },

        oldOnClick: null,

        disableSearchFields : function(disabled) {
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var searchTermsField = _amzn_utils.getById('amzn_search_textfield', widget_div);
            searchTermsField.disabled = disabled;
            if (!this.categoryFixed) {
                var searchImg = _amzn_utils.getById('selectCategoryImg', widget_div);
                if (this.oldOnClick && !disabled) {
                    searchImg.parentNode.onmouseover = this.oldOnClick;
                    this.oldOnClick = null;
                } else {
                    this.oldOnClick = searchImg.parentNode.onmouseover;
                    searchImg.parentNode.onmouseover = '';
                }
            }
            this.searchInProgress = disabled;
        },

        getSplitTitle: function(title) {
            return this.trimCharsByWidth(title, '10', this.innerWidth - 16, -1);
        },

        display_callback: function(data, isRepaint){
            if (typeof isRepaint != 'undefined' && isRepaint) {
                data = Object();
                data.NumRecords = this.totalNumOfResults;
                data.CorrectedQuery = this.correctedQuery;
                data.results = this.resultData[this.currentSearchPage];
            }
            this.isSearchCallback = true;

            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            if (typeof data == 'undefined' || typeof data.NumRecords == 'undefined' || data.NumRecords == 0) {
                var parentnode = _amzn_utils.getById('wdgt_brdr', widget_div);
                var lineArray;
                if (this.marketPlace == 'JP') {
                    lineArray = [' ', _amzn_utils.escapeHTML(this.searchTerms), _amzn_utils.escapeHTML(_amzn_utils.getString(_amzn_utils.NoResultsFor, this.marketPlace))];
                } else {
                    lineArray = [_amzn_utils.escapeHTML(_amzn_utils.getString(_amzn_utils.NoResultsFor, this.marketPlace)), _amzn_utils.escapeHTML(this.searchTerms)];
                }

                var noResultsMsgPadding = "padding:0 9px 9px 9px;"
                if (this.isIAB) {
                    noResultsMsgPadding = "padding:0 9px 4px 9px;"
                }
                parentnode.innerHTML = '<div style=\'width:' + (this.innerWidth - 30) + 'px;' + noResultsMsgPadding + 'font-family: Verdana, sans-serif; text-align:left; font-size: 10px;'+this.style_tile_h1()+'\'>'
                        + this.getSplitTitle(lineArray) + '</div>';
                if(this.isIAB) {
                    parentnode.innerHTML += this.getMsgBlankLayout();
                } else {
                    parentnode.innerHTML += this.getBlankLayout();
                }

                if (!isRepaint) {
                    this.disableSearchFields(false);
                    clearTimeout(this.searchInProgressID);
                }
                if (typeof loadComplete == 'function') {
                    loadComplete("search");
                }
                this.clearNavBar();
                this.isNavbarShown = false;
                this.setFixedHeightAttributes();
                this.setWdgtBrdrHeight();
                return;
            }
            this.totalNumOfResults = data.NumRecords;
            if(this.searchCategory=="All" && this.totalNumOfResults > 50){
                this.totalNumOfResults=50; //Hacky fix for AWS returning only 5 pages: jeetu
            }
            this.correctedQuery = data.CorrectedQuery;
            this.resultData[this.currentSearchPage] = data.results;

            // javascript associative arrays do not have a length attrb or method. Hence doing this
            var numberOfResultPages = 0;
            var minPageNumber = 10000; // a very large value
            var maxPageNumber = 0;
            for (var i in this.resultData) {
                if (_amzn_utils.objHasOwnProperty(this.resultData,i)) {
                    numberOfResultPages++;
                    minPageNumber = minPageNumber > i ? i : minPageNumber;
                    maxPageNumber = maxPageNumber < i ? i : maxPageNumber;
                }
            }

            if (numberOfResultPages > 5) {
                if (this.currentSearchPage >= maxPageNumber) {
                    this.resultData[minPageNumber] = null;
                } else {
                    this.resultData[maxPageNumber] = null;
                }
            }

            if (!isRepaint) {
                this.disableSearchFields(false);
                clearTimeout(this.searchInProgressID);
            }
            this.setFixedHeightAttributes();
            this.addResult();
            if (typeof loadComplete == 'function') {
                loadComplete("search");
            }
            this.setWdgtBrdrHeight();
        },

        addWait: function(parentnodediv){
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            _amzn_utils.getById('wdgt_brdr', widget_div).innerHTML = this.getSearchingLayout();
        },

        getNumPages: function() {
            return(Math.ceil(this.totalNumOfResults / this.totalItemsPerPage));
        },

        resetSearchTermsAndCategory: function() {
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var searchTerms = _amzn_utils.getById('amzn_search_textfield', widget_div);
            var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
            var lbel = searchDiv.textContent;
            if (typeof lbel == 'undefined' || lbel == null) {
                lbel = searchDiv.childNodes[0].nodeValue;
            }
            var searchCategoryValue = this.categoryValueFromLabel(lbel);

            searchTerms.value = this.searchTerms;
            this.selectCategory(this.searchCategory);
            searchCategoryValue = this.searchCategory;
        },

        showpage: function(page, self, templateID, marketPlace) {
            if (typeof self == 'undefined' ) {
                self = this;
            } else {
                self = all_amzn_wdgts[marketPlace][templateID][self];
                self.resetSearchTermsAndCategory();
            }
            self.currentPage = page;
            self.addResult();
        },

        computeEndPage: function() {
            var res = this.navBarBeginPage + this.resultWindowSize - 1;
            var numberOfPages = this.getNumPages();
            if (res > numberOfPages) {
                res = numberOfPages;
            }
            return res;
        },

        resultWindowSize: 5,
        serviceVersion: '',
        MarketPlace : '',


        // set widget specific variables if they have not been set
        refURL: null,
        searchTerms: null,
        searchCategory: null,
        show_image: true,
        show_price: true,
        show_review: true,
        doCurveCorners: true,
        showAmazonLogoAsText: false,
        defaultSearchTerm:"",
        useDefaultSearchTerm: false,

        wdgtHeight: undefined,
        wdgt_height: undefined,
        origWdgtWidth: undefined,
        origWdgtHeight: undefined,
        width: 120,
        innerWidth: 120,
        height: 75,
        rows: 2,
        cols: 1,
        title: 'Amazon Widget',
        category: 'stripbooks',
        categoryFixed: true,
        curveTheseCorners: ' tl tr bl br big ',
        isIAB: false,

        resultData: null, // this will be assigned the ASIN details in the display_callback function.
        totalNumOfResults: null, // this will be assigned the ASIN details in the display_callback function.
        totalItemsPerPage: 0,
        currentPage: 1,
        navBarBeginPage: 1,
        navBarEndPage: 0,
        instanceId: 0,
        requestSize: 0,
        templateId: '8002',
        searchInProgress: false,
        tag: '',
        linkCode: 'wsw',
        isSearchCallback: false,
        isNavbarShown: false,

        getTotalItemsPerPage: function() {
            var result = this.rows * this.cols;
            if( result > 20 ) {
                result = 20;
            }
            return result;
        },

        mergeTemplate: function() {
            _amzn_popup.init();
            var htmlResult = this.drawHeaderBox();

            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            widget_div.innerHTML = htmlResult;

            this._amzn_autocompletion_utils.initSearchSuggest(this.marketPlace, this);

            _amzn_utils.runPNGTransparencyHack(widget_div, this.marketPlace);
            /*Fix for string parameters passed*/
            if(typeof this.doCurveCorners =="string"){this.doCurveCorners = this.doCurveCorners=="true"};
            /*End of fix*/
            if(this.doCurveCorners){
                this.curveCorners();
            }
            if (this.category) {
                var searchText = _amzn_utils.getById('selectedCategoryDiv', widget_div);
                searchText.innerHTML = this.valueToLabel[this.category];
                if(this.isIAB && this.width < 250) {
                    searchText.innerHTML = this.trimCharsByWidth(this.valueToLabel[this.category], '10', this.width - 20, 1);
                    searchText.title = this.valueToLabel[this.category];
                }
                searchText.parentNode.onmouseover = null;
                searchText.parentNode.style['border'] = "none";
                searchText.parentNode.style['cursor'] = "text";

                var searchImg = _amzn_utils.getById('selectCategoryImg', widget_div);
                searchImg.parentNode.removeChild(searchImg);
            }
        },

        getBlankTile : function() {
            var diff = _amzn_utils.amzn_isMSIE() ? 0 : 6 * this.cols;
            var innerTileWidth = Math.floor((this.innerWidth - 6 * this.cols) / this.cols);
            return '<div class=\'wdgt_tl_pad\'><div class=\'wdgt_tl\' style=\'height:' + this.height + 'px;width:' + innerTileWidth + 'px\'></div></div>';
        },

        drawNavBar: function() {
            // This is when we have default contextual listings. No navbar should be shown now.
            var numberOfPages = this.getNumPages();
            if ((this.currentPage == 1 && numberOfPages == 0) || numberOfPages == 1) {
                this.isNavbarShown = false;
                return '<div class=\'wdgt_pgn\' style=\'' + this.style_wdgt_pgn() + '\' id=\'nav\'><div class=\'pgn_cnt\'></div></div>';
            }
            this.isNavbarShown = true;
            if (this.currentPage == this.navBarEndPage && this.currentPage < numberOfPages) {
                this.navBarBeginPage += Math.floor(this.resultWindowSize/2);
            } else if (this.currentPage == this.navBarBeginPage && this.currentPage != 1) {
                this.navBarBeginPage -= Math.floor(this.resultWindowSize/2);
            }
            this.navBarEndPage = this.computeEndPage();

            var prev = (this.currentPage == 1) ? this.currentPage : this.currentPage - 1;
            var next = (this.currentPage == numberOfPages) ? this.currentPage : this.currentPage + 1;

            var res = '<div class=\'wdgt_pgn\' style=\'' + this.style_wdgt_pgn() + '\' id=\'nav\'>';
            res+= '<div class=\'pgn_cnt\'>';
            if(prev!=this.currentPage){
                res += this.pageNumberDiv(prev, prev == this.currentPage, '&lt;');
            }
            for (var i = this.navBarBeginPage; i <= this.navBarEndPage; i++) {
                res += this.pageNumberDiv(i, i == this.currentPage);
            }
            if(next!=this.currentPage){
                res += this.pageNumberDiv(next, next == this.currentPage, '&gt;');
            }
            res += '</div>';
            res += '</div>';
            return res;
        },

        drawFooter:function() {
            return _amzn_utils.drawFooter(this);
        },

        drawHeaderBox: function() {
            if(!window.nextCallBack){
                window.nextCallBack = new Object();
            }
            if (!window.nextCallBack[this.marketPlace]) {
                window.nextCallBack[this.marketPlace] = new Object();
            }
            if (!window.nextCallBack[this.marketPlace][this.templateId]) {
                window.nextCallBack[this.marketPlace][this.templateId] = new Object();
            }
            if(!window.nextCallBack[this.marketPlace][this.templateId][this.instanceId]) {
                window.nextCallBack[this.marketPlace][this.templateId][this.instanceId] = new Object();
            }
            window.nextCallBack[this.marketPlace][this.templateId][this.instanceId]['goOnClick'] = this.goOnClick;

            var borderWidth = this.innerWidth;

            var sizeOfSearchBox = this.innerWidth > 140 ? 12 : 8;
            var brString = ' ';
            if (this.innerWidth < 235) {
                brString = '<br/>';
                // since we have a BR - we can increase the size of the search box
                if (this.innerWidth < 140) {
                    sizeOfSearchBox = 12;
                } else if (this.innerWidth < 235) { // 140 - 235
                    sizeOfSearchBox = 17;
                } else {
                    sizeOfSearchBox = 12;
                    // no BR here - reduce width
                }
            }
            if(this.innerWidth >= 250) {
                if (this.innerWidth < 270 || this.isIAB) { // 250 - 270
                    sizeOfSearchBox = 16;
                } else { // greater than 270
                    sizeOfSearchBox = 20;
                }
            }
            return '<div id=\'amzn_wdgt_t_8002_' + this.instanceId + '\' class=\'amzn_wdgt\' ' + 'style=\'' + this.style_amzn_wdgt() + '\'>'
                    + '<div class=\'amzn_wdgt_pad\' style=\'' + this.style_wdgt_pad() + '\'>'
                    + '<form id="searchBoxForm"' + 'onsubmit=\'window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].goOnClick("' + this.marketPlace + '",' + this.instanceId + ');return false;\'/>'
                    + '<div class=\'wdgt_hd\' style=\'' + this.style_wdgt_hd() + '\'>'
                    + '<div class=\'hd_input\'>'
                    + _amzn_utils.getString(_amzn_utils.Search, this.marketPlace) + ' '
                    + this.createSearchSelectbox() + brString
                    + '<span style=\'white-space:nowrap;\'><input maxlength=\'150\' id=\'amzn_search_textfield\' type=\'text\' style=\'margin:2px 2px 0 2px;font-size: 9px;padding: 1px 2px;\' size=\'' + sizeOfSearchBox +'\'/>'
                    + '<input type=\'image\' style=\'top:6px;position:relative;border: none;margin:0;cursor:pointer;\' src=\''+ _amzn_utils.imageDirectory(this.marketPlace) + '/go-rd-sec_tpng.png\' width=\'21\' height=\'21\' '
                    + 'onClick=\'javascript:window.nextCallBack["' + this.marketPlace + '"][' + this.templateId + '][' + this.instanceId + '].goOnClick("' + this.marketPlace + '",' + this.instanceId + ');\'/></span>'
                    + '</div>'
                    + '</div>'
                    + '</form>'
                    + '<div class=\'wdgt_brdr\' id=\'wdgt_brdr\' style=\'' + this.style_wdgt_brdr(borderWidth) + '\'>'
                    + '</div>'
                    + this.drawNavBar()
                    + this.drawFooter()
                    + '</div></div>';
        },

        getEditWidgetTarget: 'Amazon-Search-Widget/',

        getTile: function(result) {
            var numberOfTitleLines = 1;
        	if(this.isIAB){
        		numberOfTitleLines = this.getNumberOfTitleLines(result);
        	}
        	return _amzn_utils.getTile(result, this, undefined, numberOfTitleLines);
        },

        createPopupTile: function(result) {
            return _amzn_utils.createPopupTile(result, this);
        },

        add_pad_helper: function(value) {
            if (value) {
                return value + 'px ';
            } else {
                return '0 ';
            }
        },

        style_wdgt_pad: function() {
            var res = 'padding: ';
            res += this.add_pad_helper(this.wdgt_pad_top);
            res += this.add_pad_helper(this.wdgt_pad_right);
            res += this.add_pad_helper(this.wdgt_pad_bottom);
            res += this.add_pad_helper(this.wdgt_pad_left);
            res += ';'
            return res;
        },

        setTileHeight: function() {
            this.height = this.show_image ? 63: 28;
            if(this.show_image && !this.isIAB) {
                this.height += 10;
            }
            var innerTileWidth = Math.floor((this.innerWidth - 6 * this.cols) / this.cols);
            if (innerTileWidth <= 150 && this.show_image && !this.isIAB) {
                this.height += 16;
            }
            if (!this.show_image && this.show_price) {
                this.height += 16;
            }
            if (!this.show_image && this.show_review) {
                this.height += 15;
            }
            if (_amzn_utils.isFirefox_1_5 && !this.show_image) {
                this.height += 10;
            }
        },

        setWdgtBrdrHeight: function() {
            if(!this.isIAB) {
                return;
            }
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            var wdgt_brdr_div = _amzn_utils.getById('wdgt_brdr', widget_div);
            wdgt_brdr_div.style.height = this.getWdgtBrdrHeight() + 'px';
            if(_amzn_utils.amzn_isMSIE()) {
                var widget_inner_div = _amzn_utils.getById('amzn_wdgt_t_' + this.templateId + '_' + this.instanceId, widget_div);
                if(typeof widget_inner_div != 'undefined' && widget_inner_div != null) {
                    var diff = this.origWdgtHeight - widget_inner_div.offsetHeight;
                    wdgt_brdr_div.style.height = (this.getWdgtBrdrHeight() + diff) + 'px';
                    var widthDiff = this.origWdgtWidth - widget_inner_div.offsetWidth;
                    widget_inner_div.style.width = (this.origWdgtWidth + widthDiff) + 'px';
                }
            }
        },

        setFixedHeightAttributes: function(additionalHeightUsed) {
            if(!this.isIAB) {
                return;
            }
            if(_amzn_utils.amzn_isMSIE() && (typeof additionalHeightUsed == 'undefined' || additionalHeightUsed == null) ) {
                additionalHeightUsed = 5;
            }
            this.setTileHeight();
            var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            widget_div.style.height = this.wdgtHeight;

            this.freeHeight = this.getInnerHeight();
            if(this.isSearchCallback) {
                this.freeHeight -= 16; //search msg
                if(this.width < 250) {
                    this.freeHeight -= 24; //search msg - assumes 3 lines of msg
                }
            }
            if(typeof additionalHeightUsed != 'undefined' && additionalHeightUsed != null ) {
                this.freeHeight -= additionalHeightUsed;
            }
            this.rows = Math.floor(this.freeHeight  / (this.height+5));
            this.height = Math.floor(this.freeHeight/this.rows) - 5;
            var numberOfCols = this.width / 120.0;
            this.cols = Math.floor(numberOfCols);
            if (this.cols * 120 > this.width) {
                this.cols = Math.floor(this.width / 120);
            }

            this.totalItemsPerPage = this.getTotalItemsPerPage();
        },

        getNumberOfTitleLines: function(result) {
            var numberOfTitleLines = 1;
            var diffHeight = 0;
            if(this.show_price && !result['Price']){
                    diffHeight+=14;
            }
            if(this.show_image && !this.show_price){
                    diffHeight+=14;
            }
            if(this.show_review && !result['Rating']){
                    diffHeight+=14;
            }
            if(this.show_image && !this.show_review){
				diffHeight+=14;
            }
            var curHeight = this.height;
            this.setTileHeight();
            var tmpHeight = this.height;
            this.height = curHeight;

			if(curHeight >= tmpHeight){
                if (_amzn_utils.isFirefox_1_5() || _amzn_utils.isFirefox_2_0()) {
                    numberOfTitleLines += Math.floor((curHeight + diffHeight - tmpHeight) / 13);
                } else {
                    numberOfTitleLines += Math.floor((curHeight + diffHeight - tmpHeight) / 12);
                }
            }
            return numberOfTitleLines;
        },

        getHeadingHeight: function() {
            var headingHeight = -1;
            var widget_div = _amzn_utils.$('amazon_widget_' + this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            if (typeof widget_div != 'undefined' && widget_div != null) {
                var searchBoxForm = _amzn_utils.getById('searchBoxForm', widget_div);
                if (typeof searchBoxForm != 'undefined' && searchBoxForm != null) {
                    headingHeight = searchBoxForm.offsetHeight;
                }
            }
            return headingHeight;
        },

        getFooterHeight: function() {
            var footerHeight = -1;
            var widget_div = _amzn_utils.$('amazon_widget_' + this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
            if (typeof widget_div != 'undefined' && widget_div != null) {
                var wdgtFt = _amzn_utils.getById('wdgt_ft', widget_div);
                if (typeof wdgtFt != 'undefined' && wdgtFt != null) {
                    footerHeight = wdgtFt.offsetHeight;
                }
            }
            return footerHeight;
        },

        repaint: function(params) {
            if (typeof params.tag == 'undefined') {
                params.tag = _amzn_utils.getString(_amzn_utils.DefaultTag, this.marketPlace);
            }
            this.internalRepaint(params);
            if (this.totalNumOfResults != null) {
                this.mergeTemplate();
                var widget_div = _amzn_utils.$('amazon_widget_'+ this.marketPlace + '_' + this.templateId + '_' + this.instanceId);
                var searchTerms = _amzn_utils.getById('amzn_search_textfield', widget_div);
                var searchDiv = _amzn_utils.getById('selectedCategoryDiv', widget_div);
                searchTerms.value = this.searchTerms;
                this.selectCategory(this.searchCategory);
                this.display_callback(null, true);
            } else {
                this.topseller_display_callback(this.topsellers);
            }
            this._amzn_autocompletion_utils.initSearchSuggest(this.marketPlace, this);
        },

        internalMain: function(params) {
            if (this.marketPlace == 'US' && params.category) {
                var amznToAws = new Array();
                amznToAws['apparel'] = 'Apparel';
                amznToAws['aps'] = 'All';
                amznToAws['automotive'] = 'Automotive';
                amznToAws['baby-products'] = 'Baby';
                amznToAws['beauty'] = 'Beauty';
                amznToAws['classical'] = 'Classical';
                amznToAws['computers'] = 'PCHardware';
                amznToAws['dvd'] = 'DVD';
                amznToAws['electronics'] = 'Electronics';
                amznToAws['garden'] = 'HomeGarden';
                amznToAws['gourmet'] = 'GourmetFood';
                amznToAws['grocery'] = 'Grocery';
                amznToAws['hpc'] = 'HealthPersonalCare';
                amznToAws['jewelry'] = 'Jewelry';
                amznToAws['kitchen'] = 'Kitchen';
                amznToAws['magazines'] = 'Magazines';
                amznToAws['mi'] = 'MusicalInstruments';
                amznToAws['misc'] = 'Miscellaneous';
                amznToAws['office-products'] = 'OfficeProducts';
                amznToAws['outdoor'] = 'OutdoorLiving';
                amznToAws['photo'] = 'Photo';
                amznToAws['popular'] = 'Music';
                amznToAws['software'] = 'Software';
                amznToAws['sporting'] = 'SportingGoods';
                amznToAws['stripbooks'] = 'Books';
                amznToAws['tools'] = 'Tools';
                amznToAws['toys-and-games'] = 'Toys';
                amznToAws['vhs'] = 'VHS';
                amznToAws['videogames'] = 'VideoGames';
                amznToAws['wireless-accessories'] = 'WirelessAccessories';
                amznToAws['wireless-phones'] = 'Wireless';
                if (amznToAws[params.category]) {
                    params.category = amznToAws[params.category];
                }
            }
            this.populateCategories = _amzn_utils_populate_category.populateCategories;
            this.valueToLabel = this.populateCategories(this.marketPlace);
            if (params.category && !this.valueToLabel[params.category]) {
                params.category = null;
            }
            this.internalRepaint(params);
            this.callWebService();
        },

        topsellers: null,
        wdgt_pad_top: 8,
        wdgt_pad_left: 9,
        wdgt_pad_bottom: 0,
        wdgt_pad_right: 9,

        valueToLabel: new Array(),

        getWidth: function() {
            return this.innerWidth;
        },

    /*Locale_specific_stuff_local_BEGIN*/
defaultSearchCategoryValue: 'All',
marketPlace: 'US',/*Locale_specific_stuff_local_END*/


/*Theme_specific_stuff_BEGIN*/
internalRepaint: function(params) {
    this.origParams = _amzn_utils.clone(params);
    params = _amzn_utils.escapeHTML(params);
    this.useDefaultSearchTerm = params.use_default_search_term;
    this.defaultSearchTerm = params.default_search_term;
    this.showAmazonLogoAsText = _amzn_utils.getValidParam(params.showAmazonLogoAsText, false);
    this.show_image = params.show_image;
    this.show_price = params.show_price;
    this.show_review = params.show_review;
    this.doCurveCorners = params.curve_corners;
    
    this.width = parseInt(params.width);
    this.wdgtHeight = parseInt(params.height);
    this.wdgt_height = this.wdgtHeight;
    this.origWdgtWidth = this.width;
    this.origWdgtHeight = this.wdgtHeight;
    if (typeof this.wdgtHeight != 'undefined' && !isNaN(this.wdgtHeight)) {
        this.isIAB = true;
    } else {
        this.isIAB = false;
    }
    this.rows = params.rows;
    this.cols = params.cols;
    this.validateRowsAndColumns();
    this.serviceVersion = params.serviceVersion;
    this.MarketPlace = params.MarketPlace;
    this.refURL = params.refURL;
    this.tag = params.tag;
    this.isWidgetSource = typeof params.isWidgetSource != 'undefined';
    if (this.width < 150) {
        this.wdgt_pad_right = 5;
        this.wdgt_pad_left = 5;
    }
    this.innerWidth = this.width - this.wdgt_pad_right - this.wdgt_pad_left;

    if (params.outer_bkgd_color) { this.outer_bkgd_color = params.outer_bkgd_color; }
	if (params.head_text_color) { this.head_text_color = params.head_text_color; }
	if (params.inner_bkgd_color) { this.inner_bkgd_color = params.inner_bkgd_color; }
    if (params.text_color) { this.text_color = params.text_color; }
    if (params.price_color) { this.price_color = params.price_color; }

    this.wdgt_color = this.head_text_color;
    this.wdgt_pgn_a_color = this.head_text_color;
    this.wdgt_ft_a_color = this.head_text_color;
    this.wdgt_pgn_color = this.head_text_color;

    this.wdgt_tl_h2_color = this.text_color;

    if (params.category) {
        this.category = params.category;
        this.categoryFixed = true;
    } else {
        this.category = null;
        this.categoryFixed = false;
    }

    if (typeof params.theme_version == 'undefined') {
        this.theme_version = '0';
    } else {
        this.theme_version = params.theme_version;
    }

    this.setTileHeight();
    this.setFixedHeightAttributes();

    this.totalItemsPerPage = this.getTotalItemsPerPage();
    this.navBarEndPage = this.computeEndPage();
    this.requestSize = this.totalItemsPerPage > 10 ? this.totalItemsPerPage : 10;

    _amzn_utils.insertStyleSheet('stylesheet.widgets.amazon.com', '/css/widgets.css', this.marketPlace);
},

inner_bkgd_color: '#b3c1c8',
outer_bkgd_color: '#4a6676',
text_color: '#31658b',
price_color: '#3f3c39',
head_text_color: '#eae493',
doCurveCorners: true,

brdr_margin_top: 10,
brdr_margin_bottom: 10,
brdr_margin_right: 10,
brdr_margin_left: 10,
wdgt_hd_color: '#FFFFFF',
wdgt_pgn_a_color: '#FFFFFF',
wdgt_ft_a_color: '#FFFFFF',
wdgt_tl_h1_a_color: '#666666',
wdgt_tl_h2_color: '#666666',
wdgt_tl_cmnt_color: '#666666',
wdgt_pgn_color: '#000000',
wdgt_brdr_bkgd_img: 'bg4_tpng.png',


style_pgn_strong : function() {
    return 'background-color: ' + this.wdgt_ft_a_color + ';color:' + this.outer_bkgd_color + ';';
},
style_pgn_a: function() {
    return 'text-decoration:none;color: ' + this.wdgt_pgn_a_color + ';';
},
style_amzn_wdgt: function() {
    return 'color:' + this.wdgt_color + ';background: ' + this.outer_bkgd_color + ';width:' + this.width + 'px;';
},
style_wdgt_hd: function() {
    var style = 'text-align: left;font: bold 12px / 1em Verdana, Arial, Helvetica, sans-serif;color: ' + this.head_text_color +';';
    if(this.isIAB) {
        style += "padding-top: 0px; padding-bottom: 3px;";
    }
    return style;
},
style_wdgt_brdr: function(borderWidth) {
    var style = 'background: ' + this.inner_bkgd_color
            + ' url(' + _amzn_utils.imageDirectory(this.marketPlace) + '/' + this.wdgt_brdr_bkgd_img + ') repeat-x;';
    if(this.isIAB) {
        style += ' padding-top: 2px; ';
    }
    return style;
},
style_wdgt_ft: function() {
    if(this.isIAB) {
        //return "padding-top: 1px; padding-bottom: 5px;";
    }
    return '';
},
style_wdgt_ft_a: function() {
    return 'border-bottom: 1px dotted ' + this.wdgt_ft_a_color + ';color:' + this.wdgt_ft_a_color + ' !important;';
},
style_wdgt_pgn: function() {
    return 'color: ' + this.wdgt_ft_a_color + ';';
},
style_wdgt_pop_tl: function(innerTileWidth) {
    return 'border: 2px solid ' + this.outer_bkgd_color
            + ';color:' + this.wdgt_color + ';background: ' + this.inner_bkgd_color
            + ';width:' + innerTileWidth + 'px';
},
style_tile_a: function() {
    return 'border-bottom: none; text-decoration:none;color: ' + this.text_color + ' !important;';
},
style_tile_h1_a: function() {
    return '';
},
style_tile_h1: function() {
    return 'color: ' + this.text_color + ' !important;';
},
style_get_edit_wdgt: function() {
    return 'color: ' + this.text_color+ ' !important;border-bottom: 1px dotted ' + this.text_color + ';';
},
style_tile_h2: function() {
    return 'color: ' + this.price_color + ' !important;';
},
style_tile_category: function() {
    return 'color: ' + this.price_color+ ' !important;';
},
style_tile_price: function() {
    return 'color: ' + this.price_color + ' !important;';
},
style_tile_asin_img: function() {
    return 'border-bottom: none; text-decoration:none;';
},
style_tile_asin_a: function() {
    return 'border-bottom: none; text-decoration:none;';
},
style_tile_review: function() {
    return 'color: ' + this.price_color + ' !important;';
},
display_template_id: 6,
style_tile_comment: function() {
    return 'color: ' + this.price_color + ' !important;';
},
getBackgroundColor: function() {
    return this.outer_bkgd_color;
},
getGetWidgetColor: function() {
    return this.head_text_color;
},
getInnerTileHeight: function() {
    var headingHeight = 37;
    var bottomHeight = 37;
    if(this.width <= 250) {
        headingHeight = 50;
        bottomHeight = 52;
    }
    if(_amzn_utils.isFirefox() && this.width > 250 && this.marketPlace=='FR'){
        bottomHeight += 1;
    }
    var renderedHeadingHeight = this.getHeadingHeight();
    if( renderedHeadingHeight != -1 ) {
        headingHeight = renderedHeadingHeight + 8;
    }
    var renderedFooterHeight = this.getFooterHeight();
    if( renderedFooterHeight != -1 ) {
        bottomHeight = renderedFooterHeight;
    }
    var height = this.wdgtHeight - (headingHeight + bottomHeight);
    return height;
},
getInnerHeight: function(navBarPresent) {
    //Depending on width the bottom height can be Headi
    //8px padding for top tile + Heading+Get Widget+ Amazon.com + Nav bar .. Get widget button will change to new widget text.
    var bottomHeight = 0; //navbar padding
    var availableHeight = this.getInnerTileHeight() - bottomHeight - 2; // 8 is the top padding
    if (this.isSearchCallback && this.getNumPages() > 1) {
        availableHeight -= 12;
    }
    return availableHeight;
},
getWdgtBrdrHeight: function() {
    var innerHeight = this.getInnerHeight();
    if (_amzn_utils.amzn_isMSIE()) {
        innerHeight += 2;
        if (!this.categoryFixed) {
            innerHeight += 1;
        }
    }
    return innerHeight;
}

/*Theme_specific_stuff_END*/
    }

    var js_display_template_id = '' + wdgt.display_template_id; // convert to string

    // Loop thru all the wdgts data and check which one uses the current template.
    // Then mark that as done and get the instanceId from the stored data.
    var id = null;
   if( typeof amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId] !="undefined"){
    for (var i = 0; i < amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId].length; i++) {
        var wdgt_params = amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][i];
        if (wdgt_params.displayTemplate == js_display_template_id && !wdgt_params.isTaken) {
            wdgt_params.isTaken = true;
            id = wdgt_params.instanceId;
            break;
        }
    }
    if (id == null) {
        id = 0;
    }

    wdgt.instanceId = id;
    all_amzn_wdgts[wdgt.marketPlace][wdgt.templateId][id] = wdgt;
    if (typeof amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id] != 'undefined') {
        if(typeof amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id].tag =='undefined'){
            amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id].tag = _amzn_utils.getString(_amzn_utils.DefaultTag, wdgt.marketPlace);
        }

        if (wdgt.isWidgetSource && (wdgt.templateId == '8001' || wdgt.templateId == '8002')) {
            _amzn_utils.recordImpression(amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id].tag, wdgt.linkCode,  wdgt.marketPlace);
        } else {
            _amzn_utils.recordImpression(amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id].tag, wdgt.linkCode,  wdgt.marketPlace);
        }
        amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id].hasLoaded = true;

        wdgt.internalMain(amzn_wdgts_vars[wdgt.marketPlace][wdgt.templateId][id]);
    }
}
}
if (typeof all_amzn_wdgts == 'undefined') { all_amzn_wdgts = new Array(); }

/*Locale_specific_stuff_global_BEGIN*/
var curr_mkt_place = 'US';/*Locale_specific_stuff_global_END*/


if (typeof all_amzn_wdgts[curr_mkt_place] == 'undefined') { all_amzn_wdgts[curr_mkt_place] = new Array(); }
if (typeof all_amzn_wdgts[curr_mkt_place]['8002'] == 'undefined') { all_amzn_wdgts[curr_mkt_place]['8002'] = new Array(); }
var curr_wdgt = all_amzn_wdgts[curr_mkt_place]['8002'];

function clearWidgets() {
    try{
       document.body.removeChild(all_amzn_wdgts[amzn_wdgt.marketPlace][amzn_wdgt.templateId][0]._amzn_autocompletion_utils.getSearchSuggest());
    }catch(e){}
    amzn_wdgts_vars = new Array();
    amzn_wdgts_vars[amzn_wdgt.marketPlace] = new Array();
    amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId] = new Array();

    all_amzn_wdgts = new Array();
    all_amzn_wdgts[amzn_wdgt.marketPlace] = new Array();
    all_amzn_wdgts[amzn_wdgt.marketPlace][amzn_wdgt.templateId] = new Array();

    amzn_wdgts_vars[amzn_wdgt.marketPlace][amzn_wdgt.templateId].push(_amzn_utils.clone(amzn_wdgt));
}

function search_callback(data) {
    if (_amzn_utils.amzn_isMSIE()) {
        setTimeout(new function() {
            if (typeof _amzn_popup == 'object') {
                all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].display_callback(data);
            } else {
                search_callback(data);
            }
        }, 50);
    } else {
        all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].display_callback(data);
    }
}

function topseller_display_callback(data) {
    if (_amzn_utils.amzn_isMSIE()) {
        setTimeout(new function() {
            if (typeof _amzn_popup == 'object' && typeof Nifty =='function') {
                if (typeof data == 'undefined' || typeof data.results == 'undefined') {
                    all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].topseller_display_callback(new Array());
                } else {
                    all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].topseller_display_callback(data.results);
                }
            } else {
                topseller_display_callback(data);
            }
        }, 50);
    } else {
        if (typeof data == 'undefined' || typeof data.results == 'undefined') {
            all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].topseller_display_callback(new Array());
        } else {
            all_amzn_wdgts[data.MarketPlace]['8002'][data.InstanceId].topseller_display_callback(data.results);
        }
    }
}

function _amzn_wdgt_8002_updateCompletionCallback() {
    if (completion && completion.length && completion.length >= 1) {
        _amzn_wdgt_8002_updateCompletionHandler.updateCompletion(completion[1]);
    }
}

initOnloadFunctions();

