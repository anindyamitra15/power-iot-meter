const pick = (ssid) => {
  if (!ssid) return;
  $("#ssid").val(ssid);
};

const scanAps = () => {
  $.ajax({
    url: "scan",
  }).done((data) => {
    if(!data) return;
    const nets = (typeof data == 'string')?JSON.parse(data):data;
    if (nets) {
      let table_body = `<tr><td>No.</td><td>SSID</td><td>RSSI</td><td>Secure</td></tr>`;
      nets.forEach((net) => {
        table_body += `<tr><td>${net?.id}</td><td onclick="pick('${net?.ssid}')">${net?.ssid}</td><td>${net?.rssi}</td><td>${net?.enc}</td></tr>`;
      });
      $("#scans").html(table_body);
    }
  });
};

$(document).ready(() => {
  scanAps();
});
