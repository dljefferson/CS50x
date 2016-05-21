<?php

    // configuration
require("../includes/config.php");
//get session id (user id)
$sessionId = $_SESSION["id"];   
//get total cash on hand
$cash = CS50::query("SELECT cash FROM users WHERE id = $sessionId");
//get form info via POST
$formInfo = $_POST;
//get stock info

    if(empty($formInfo))
    {
        render("buy_form.php", ["title" => "Buy"]);
    }  
    else 
    {
        //check for invalid input
        $stockInfo = lookup($formInfo["symbol"]);
        
        if(empty($stockInfo["symbol"]))
        {
            apologize("You must specify a stock to buy.");
        }
        if(empty($formInfo["shares"])) 
        { 
            apologize("You must specify a number of shares");
        }
        if(preg_match("/^\d+$/", $formInfo["shares"]) == false)
        {
            apologize("Invalid number of shares.");
        }
        else
        {
            $stockSymbol = $stockInfo["symbol"];
            $stockShares = CS50::query("SELECT shares FROM portfolios WHERE user_id = $sessionId AND symbol = '$stockSymbol'");
            $stockPrice = $stockInfo["price"];
            $stockTotal = $formInfo["shares"] * $stockInfo["price"];
            
            //check to see if user has enough cash
            if($stockTotal > $cash[0]["cash"])
            {
                apologize("You can't afford that.");
            }
            
            else
            {
                  $shares = $formInfo["shares"];
                  $newShares = $stockShares[0]["shares"] + $formInfo["shares"];
                  $newCash = $cash[0]["cash"] -  $stockTotal;
                  
                  CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES($sessionId, '$stockSymbol', $shares) ON DUPLICATE KEY UPDATE shares = $newShares"); 
                  CS50::query("UPDATE users SET cash = $newCash WHERE id = $sessionId");
                  CS50::query("INSERT INTO history (user_id, transaction, date_time , symbol, shares, price) VALUES($sessionId, 'BUY', CURRENT_TIMESTAMP, '$stockSymbol', $shares, $stockPrice)");
                  
                  redirect("index.php");
            }
        }
        
    }
    
?>    
    