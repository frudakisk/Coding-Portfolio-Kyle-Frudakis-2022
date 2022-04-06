/*global document*/

var report = function (minute, second) {
    document.getElementById("result").innerHTML =
        minute + "min = " + second + "s";
};

document.getElementById("sec_to_min").onclick = function () {
    var sec = document.getElementById("time").value;
    var seconds = (sec * 0.0166667);
    report(seconds.toFixed(2), sec);
};

document.getElementById("min_to_sec").onclick = function () {
    var min = document.getElementById("time").value;
    var minutes = (min * 60);
    report(min, minutes.toFixed(2));
};