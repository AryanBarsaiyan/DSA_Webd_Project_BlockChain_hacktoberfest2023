$(".qtext").click(function(event){
// $(this).css({"color":"hsl(238, 29%, 16%)","font-weight":"700"});
  $(".collapse").hide();
  $(this).parent().next().show();
  close();
  $(this).find(".btn").toggleClass("arrow");
});
function close(){
  $(".qtext").find(".btn").removeClass("arrow");
  // $(".qtext").css({"color":"hsl(238, 29%, 16%)","font-weight":"700"};
}
