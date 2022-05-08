const scanAps = () => {
  $.ajax({
    url: "http://192.168.0.210/scan",
  }).done((nets) => {
    let table_body = `<tr><td>No.</td><td>SSID</td><td>RSSI</td><td>Secure</td></tr>`;
    $.each(nets, (_, net) => {
      table_body += `<tr><td>${net?.id}</td><td>${net?.ssid}</td><td>${net?.rssi}</td><td>${net?.enc}</td></tr>`;
    });
    $("#scans").html(table_body);
  });
};

$(document).ready(() => {
  scanAps();

});