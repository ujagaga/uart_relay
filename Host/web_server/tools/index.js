function setPreviewSize(){
	var img = document.getElementById('video_stream');

	var width  = (window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth) - 20;
	const height = (window.innerHeight|| document.documentElement.clientHeight|| document.body.clientHeight) - 60;
    if(width > 1280){
        width = 1280;
    }
	img.style.width = width + 'px';
	img.style.height = 'auto';

	if(img.height > height){
		img.style.height = height + 'px';
		img.style.width = 'auto';
	}

	document.getElementById('container').setAttribute("style","width:" + img.clientWidth + "px");
}

function set_home_url(){
    if(window.location.hostname.endsWith(".local")){
        href = window.location.protocol + "//" + window.location.hostname + ":8080";
        document.getElementById('on_btn').href = href + "/relay_on";
        document.getElementById('off_btn').href = href + "/relay_off";
    }
}

function set_stream_url(){
  /* Extract connection parameters */
  var stream_user = document.getElementById('stream_user').value;
  var stream_pass = document.getElementById('stream_pwd').value;

  /* Set streaming img source */
  document.getElementById('video_stream').src = window.location.protocol + "//" + stream_user + ":" + stream_pass + "@" +
  window.location.hostname + ":8013/stream";
}

window.onload = function() { 
    set_home_url();
    set_stream_url();
    setPreviewSize();
}