<?php

    // configuration
    require("../includes/config.php"); 

   
   // Get session id 
   $sessionId = $_SESSION["id"];
   $rows  =  CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = $sessionId");      
   $cash = CS50::query("SELECT cash FROM users WHERE id = $sessionId"); 
   
   //build associative array for portfolio form
   if(!empty($rows))
   {
       foreach($rows as $row)
       {
           $symbol = $row["symbol"];
           $stockInfo = lookup($symbol);
           $total = $row["shares"] * $stockInfo["price"];
           if($stockInfo !== false)
           {
               $positions[] = [
               "name" => $stockInfo["name"],
               "price" => $stockInfo["price"],
               "shares" => $row["shares"],
               "symbol" => $row["symbol"],
               "total" => $total
             ];
            }
           
        }
         
       render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => $cash[0]]);  
    } 
    else
    {
        render("portfolio.php", [ "title" => "Portfolio", "cash" => $cash[0]]);
    }
?>
                   