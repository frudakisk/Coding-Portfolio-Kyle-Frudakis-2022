<!DOCTYPE html>
<!--This file will not work without a server to host it. Present raw code when no server available-->
<html>
  <title>Weather API</title>
  <header>
    <link href="css/weatherAPI.css" rel="stylesheet">  
  </header>
  <body>
    <header id="header">Weather for You</header>
<div class="main_container">
      <div class="child_container">
            <?php
      error_reporting(0);
      if ($_SERVER["REQUEST_METHOD"] == "POST")
      {
          $userZip = $_POST["Zip"];
          $userUnits = $_POST["Unit"];
          //echo $userZip, $userUnits;

          $apiUrl = "http://api.openweathermap.org/data/2.5/weather";
          $queryString = "zip=$userZip&units=$userUnits&appid=67be52b2599b50324fad4ae10eba18e4";

          // Make HTTP request and wait for the response
          $response = file_get_contents("$apiUrl?$queryString");

          if ($response === FALSE) {
              echo "<p>Invalid Zip Code</p>";
              echo "<p>Zip Codes are 5 digits long...some may be still invalid";
          } else {
              // Convert JSON response into PHP object
              $obj = json_decode($response);
              //print_r($obj); //for developing purposes...delete later

              echo"<p>Current Zip Code: $userZip </p>";
              $cityName = $obj->name;
              echo"<p>City: $cityName </p>";
              $currentTemp = $obj->main->temp;
              $windSpeed = $obj->wind->speed;
              if($userUnits == "imperial")
              {   
                  echo "<p>Current temp: $currentTemp &deg;F</p>";
                  echo"<p>Wind Speed: $windSpeed mph</p>";
              }
              else if ($userUnits == "metric")
              {
                  echo "<p>Current temp: $currentTemp &deg;C</p>";
                  echo"<p>Wind Speed: $windSpeed kph</p>";
              }
              $description = $obj->weather[0]->description;
              echo "<p>Description: $description</p>";
              $humidity = $obj->main->humidity;
              echo "<p>Humidity: $humidity%</p>";  
        }
      }
?>
      
      <form method="post" action="index.php">
          <p>Zip Code<input type="number" name="Zip" min="00501" max="99950" autofocus></p> <!--detect only numbers-->
          <label>Unit:</label>
          <select name="Unit">
            <option name="Imperial" value="imperial">Imperial</option>
            <option name="Metric" value="metric">Metric</option>  
          </select>
          <p><input type="submit" name="Submit" id="button"></p>
      </form>
      </div>
    <div class="child_container">
        <img src="images/weather_symbols.jpg">
    </div>
</div>    

      <footer id="footer">
          <div class="main_container">
              <div class="child_container">Created By: Kyle Frudakis</div>
              <div class="child_container"> Weather info from: <a href="https://openweathermap.org/" target="_blank">https://openweathermap.org/</a></div>
          </div>
      </footer>
  </body>
</html>