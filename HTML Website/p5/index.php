<!DOCTYPE html>    <!-- index.php -->
<!--This file will not work without a server to host it. Present raw code when no server available-->


<html>
  <head>
    <title>Guess a Number</title>
    <link rel="stylesheet" href="css/p5.css">
  </head>

    <header id="header">
        <h1>The Guessing Game</h1>
    </header>
    
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $randNum = rand(1, 10);
    
    if($randNum == $_POST["num"])
    {
        echo "<h1>Correct!</h1>";
    }
    else if ($_POST["num"] == "")
    {
        echo "<p>Please enter a number</p>";
        //something here
    }
    else if ($randNum < $_POST["num"])
    {
        echo "<p>Your pick was too high</p>";
    }
    else if ($randNum > $_POST["num"])
    {
        echo "<p>Your pick was too low</p>";
    }
    
    echo "<p>Your last guess was ".$_POST["num"];
    
    echo "<p>The real number was $randNum</p>";
    
}
?>

<body>
    <form method="post" action="index.php">
    <p>I'm thinking of a number between 1 and 10.</p>
    <p>Your guess? <input type="number" name="num" min="1" max="10" autofocus></p>
    <input type="submit" value="Guess">
    </form>
</body>

    
    <footer id="footer">
    <p>this is a footer</p>
    </footer>
</html>

