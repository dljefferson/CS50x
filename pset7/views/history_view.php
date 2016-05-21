

  <div id="middle td">
    <table class="table table-striped">
      <thead>
          <tr>
            <th>Transaction</th>	
            <th>Time/Date</th>
            <th>Symbol</th>
            <th>Shares</th>	
            <th>Price</th>
          </tr>
      </thead>
      <tbody>
      <?php if(!empty($positions)): ?>
        <?php foreach ($positions as $position): ?>
           <tr>
             <td><?= $position["transaction"] ?></td>
             <td><?= $position["date_time"] ?></td>
             <td><?= $position["symbol"] ?></td>
             <td><?= $position["shares"] ?></td>
             <td>$<?= number_format($position["price"], 2) ?></td>
           <tr/>
        <?php endforeach ?>
       <?php endif ?> 
      </tbody>
    </table>
  </div>