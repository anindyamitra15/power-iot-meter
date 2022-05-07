const scanAps = () => {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange =()=>{
    if (this.readyState == 4 && this.status == 200) {
      //apppend the list to the document with id = "scan"
      console.log(this.Response);
    }
    xhttp.open("GET", "ajax_info.txt", true);
    xhttp.send();
  };
};

$(document).ready(() => {});
