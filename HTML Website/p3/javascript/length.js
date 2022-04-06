/*global document*/

var report = function (meter, foot) {
    document.getElementById("result").innerHTML =
        meter + "m = " + foot + "ft";
};

document.getElementById("feet_to_meter").onclick = function () {
    var foot = document.getElementById("length").value;
    var feet = (foot * 0.3048);
    report(feet.toFixed(2), foot);
};

document.getElementById("meter_to_feet").onclick = function () {
    var meter = document.getElementById("length").value;
    var meters = (meter * 3.28084);
    report(meter, meters.toFixed(2));
};