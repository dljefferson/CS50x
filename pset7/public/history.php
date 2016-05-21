<?php

    // configuration
    require("../includes/config.php"); 

   
   // Get session id 
   $sessionId = $_SESSION["id"];
   $rows  =  CS50::query("SELECT transaction, date_time, symbol, shares, price FROM history WHERE user_id = $sessionId");      
    
   
   if(!empty($rows))
   {
       foreach($rows as $row)
       {
           
           
               $positions[] = [
               "transaction" => $row["transaction"],
               "date_time" => $row["date_time"],
               "symbol" => $row["symbol"],
               "shares" => $row["shares"],
               "price" => $row["price"]
             ];
            
           
        }
         
       render("history_view.php", ["positions" => $positions, "title" => "History"]);  
    } 
    else
    {
        render("history_view.php", [ "title" => "history"]);
    }
?>
                   