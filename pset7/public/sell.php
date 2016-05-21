<?php

require("../includes/config.php"); 

   
       $sessionId = $_SESSION["id"];
       $portfolio  =  CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = $sessionId");      
       $cash = CS50::query("SELECT cash FROM users WHERE id = $sessionId");
       
       //get stock to be sold
       $soldStock = $_POST;
      
       //render sell form
       if(empty($_POST ))
       {
          render("sell_form.php", ["title" => "Sell", "symbol" => $portfolio]);  
          
       }  
       else
       {
           if(!empty($portfolio))
           {
                 $stockSoldSymbol = $soldStock["symbol"];
                 $stockInfo = lookup($soldStock["symbol"]);
                 $stockPrice = $stockInfo["price"];
                 $shares = $portfolio[0]["shares"];
                 $total = $stockInfo["price"] * $portfolio[0]["shares"];
           
                 if($portfolio[0]["symbol"] == $soldStock["symbol"])  
                 {
                        $newCash = $cash[0]['cash'] + $total;
           
                        CS50::query("UPDATE users SET cash = $newCash WHERE id = $sessionId");
                        CS50::query("DELETE FROM portfolios WHERE user_id = '$sessionId' AND symbol = '$stockSoldSymbol'");
                        CS50::query("INSERT INTO history (user_id, transaction, date_time , symbol, shares, price) VALUES($sessionId, 'SELL', CURRENT_TIMESTAMP, '$stockSoldSymbol', $shares, $stockPrice)");
                        redirect("index.php");
                 }
                 
                  
            }
            else
            {
            
            apologize("Nothing to sell.");
            
            }
         
         apologize("You must chose stock"); 
        
           
       } 
      
        
    
          
       
?>       