<?php

    // configuration
    require("../includes/config.php"); 

    // render quote
    
     if($_SERVER["REQUEST_METHOD"] == "POST")
     {
         
          $_POST= lookup($_POST["symbol"]);   
          
          if($_POST == false)
          {
              apologize("You must enter a valid symbol");
          }
          else
          {     
              render("quote_price.php", ["title" => "Quote"]);
          }
     }  
     else
     {
         render("quote_form.php", ["title" => "Quote"]);
     }
    
    
    
 
      
?>
