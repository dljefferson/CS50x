<form action="sell.php" method="post">
    <fieldset>
       
        <div class="form-group">
            <select class="form-control" name="symbol">
              <option disable selected value>Symbol</option>
               <?php 
                 
                 foreach($symbol as $name) 
                 {
                     echo '<option value="'.$name["symbol"].'">'.$name["symbol"].'</option>';
                 }
               ?> 
            </select>
        </div>
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>