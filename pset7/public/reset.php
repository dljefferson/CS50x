<?php

    // configuration
    require("../includes/config.php");

    $sessionId = $_SESSION["id"];
    $currentPassword = CS50::query("SELECT hash FROM users WHERE id = $sessionId");
   
    if (empty($_POST))
    {
        // else render form
        render("reset_form.php", ["title" => "Password Reset"]);
    }

    
    else
    {
        //check for valid inputs
        if(empty($_POST["password"]))
        {
            apologize("You must provide password.");
        }
    
        if($_POST["new_password"] != $_POST["confirmation"])
        {
            apologize("Passwords do not match.");
        }
        if(empty($_POST["new_password"]))
        {
           apologize("You must provide new password."); 
        }
        if(empty($_POST["confirmation"]))
        {
           apologize("You must confirm new password."); 
        }
        
       
        if(!password_verify($_POST["password"], $currentPassword[0]["hash"]))
        {
            apologize("You must provide a valid password."); 
        }
        //update password hash
        else
        {
            $newHash = password_hash($_POST["new_password"], PASSWORD_DEFAULT);
            
            
            CS50::query("UPDATE users SET hash = '$newHash' WHERE id = $sessionId");
        
            render("reset_message.php");
        }
     
    
        
    }

?>