function gpio2Toggle() {
  Console.log("Imm'a toggle your GPIO homie!");
  ajaxReq("POST", "/thoughtworks/gpio2Toggle", function (resp) {
    showNotification("Your outputs have been toggled!!!");
  }, null, null);
}
