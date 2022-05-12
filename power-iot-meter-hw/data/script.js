const pick = (ssid) => {
    if (!ssid) 
        return;
    
    $("#ssid").val(ssid);
};
const scanAps = () => {
    $.ajax({url: "scan"}).done((data) => {
        if (!data) 
            return;
        
        const nets = (typeof data == 'string') ? JSON.parse(data) : data;
        if (nets) {
            let table_body = "";
            nets.forEach((net) => {
                table_body += `<tr><td>${
                    net ?. id
                }</td><td onclick="pick('${
                    net ?. ssid
                }')">${
                    net ?. ssid
                }</td><td>${
                    net ?. rssi
                }</td><td>${
                    net ?. enc
                }</td></tr>`;
            });
            $("#scans").html(table_body);
        }
    });
};
const passCheck = ()=> {
    $('#pass').keyup(()=>{
        var countText = $('#pass').val().length;
        $('p').html((countText > 0 && countText < 8)?'Your Password should be 8 characters long!':'');
        $(':input[type="submit"]').prop('disabled', (countText > 0 && countText < 8)?true:false);
    })
};

$(document).ready(() => {
    scanAps();
    passCheck();
});
