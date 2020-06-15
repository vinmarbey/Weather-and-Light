const char WETTERSTATION[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="de">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wetterstation</title>
    //<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB" crossorigin="anonymous">

    <style>
      /* Sticky footer styles
      -------------------------------------------------- */
      html {
        position: relative;
        min-height: 100%;
      }
      body {
        /* Margin bottom by footer height */
        margin-bottom: 60px;
        background-color: #161618;
        color: #f2f5f4;
        
      }
      .footer {
        position: absolute;
        bottom: 0;
        width: 100%;
        /* Set the fixed height of the footer here */
        height: 60px;
        line-height: 60px; /* Vertically center the text there */
        background-color: #212529;
      }
      
      table {
        background-color: #161618;
    border-collapse: collapse;
    border: none;
    }
    thead {
    background-color: #212529;
    }
    tfoot {
    background-color: #212529;
    font-size: 80%;
    border-top: 1px solid #999;
    }
    td, th {
    text-align: left;
    padding: 0.5em 1em;
        border: 1px solid #f2f5f4;
    }
      tr:nth-child(even) {background-color: #212529;}
      

      /* Custom page CSS
      -------------------------------------------------- */
      /* Not required for template or sticky footer method. */

      body > .container {
        padding: 30px 15px 0;  
      }

      .footer > .container {
        padding-right: 15px;
        padding-left: 15px;
      }

      code {
        font-size: 80%;
      }
    </style>
  </head>
  <body>
    <header>
    <!-- Fixed navbar -->
    <nav class="navbar navbar-expand-md navbar-dark fixed-top bg-dark">
      <a class="navbar-brand" href="#">Wetterstation</a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarCollapse" aria-controls="navbarCollapse" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarCollapse">
        <ul class="navbar-nav mr-auto">
            <a class="nav-link" href="/admin">Admin</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/ui">RGB Controller</a>
          </li>
          <li class="nav-item active">
            <a class="nav-link" href="#">Wetterstation <span class="sr-only">(current)        </span></a>
          </li>
          <li class="nav-item">
          
        </ul>
      </div>
    </nav>
  </header>

  <!-- Begin page content -->
  <main role="main" class="container">
  <!body scroll="no" style="overflow: hidden">
      <div style="height: 15px;"></div>
      <div class="container">
        <div class="row">
          <div class="col-sm">
          </div>
          
          <div class="col-6">
          <h2>Wetterstation</h2>
          <table>
      <thead>
      <tr>
        <th>Nr. </th>
        <th>Messwert</th>
        <th>Wert</th>
      </tr>
      </thead>
      <tfoot>
      <tr>
        <td colspan="3">aktuelle Werte</td>
      </tr>
      </tfoot>
      <tbody>
      <tr>
        <td>1.</td>
        <td>Temperatur</td>
        <td><p>The temperature is: <span>75oF</span>.</p> °C</td>
      </tr>
      <tr>
        <td>2.</td>
        <td>Luftfeuchte</td>
        <td>... %</td>
      </tr>
      <tr>
        <td>3.</td>
        <td>Luftdruck</td>
        <td>... hPa</td>
      </tr>
            <tr>
        <td>4.</td>
        <td>Globalstrahlung</td>
        <td>... W/m²</td>
      </tr>
      </tbody>
    </table>
          </div>
          <div class="col-sm">
          </div>
        </div>
      </div>
    </main>

    <footer class="footer">
      <div class="container">
        <span class="text-muted">Wetterstation</span>
      </div>
    </footer>

    <script src="https://code.jquery.com/jquery-3.3.1.min.js" integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
    <script>
    $("#submitValues" ).click(function() {
      var red = parseInt($('#inputRValue').val());
      var blue = parseInt($('#inputBValue').val());
      var green = parseInt($('#inputGValue').val());
      
      var json = {state:"ON",brightness:100,color:{mode:"rgb",r:red,g:green,b:blue},mode:"SOLID"};
      console.log(json);
      console.log(JSON.stringify(json));
      
      $.ajax("/api/v1/state", { data: JSON.stringify(json), dataType: "json", method: "POST", contentType: "application/json", cache: false, timeout: 2000})
        .done(function( data ) {
          console.log( "Response: " );
          console.log( data );
          //alert(data);
        })
        .fail(function( data ) {
          console.log( "Error: " );
          console.log( data );
        //  alert(data);
        });
    });
    </script>
  </body>
</html>
)=====";
