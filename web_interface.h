const char WEBINTERFACE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="de">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED Steuerung</title>
    //<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB" crossorigin="anonymous">
    <script type="text/javascript" src="iro.min.js"></script>
    <script type="text/javascript" src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
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

      /* Custom page CSS
      -------------------------------------------------- */
      /* Not required for template or sticky footer method. */

      body > .container {
        padding: 100px 15px 0;
        background-color: #161618;  
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
      <a class="navbar-brand" href="/">LED Steuerung</a>
      <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarCollapse" aria-controls="navbarCollapse" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarCollapse">
        <ul class="navbar-nav mr-auto">
            <a class="nav-link" href="/admin">Admin</a>
          </li>
          <li class="nav-item active">
            <a class="nav-link" href="#">RGB Controller <span class="sr-only">(current)        </span></a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/weather">Wetterstation</a>
          </li>
          
          <li class="nav-item">
          
        </ul>
      </div>
    </nav>
  </header>

 <main role="main" class="container">
 <body scroll="no" style="overflow: hidden">
  <div id="color-picker-container"></div>
  <script type="text/javascript">
      var size = 0;
      if (window.innerWidth > window.innerHeight) {
        size = window.innerHeight * 0.65;
      } else {
        size = window.innerWidth * 0.8;
      }

      var demoColorPicker = new iro.ColorPicker("#color-picker-container", {
      // color picker options
      // Option guide: https://rakujira.jp/projects/iro/docs/guide.html#Color-Picker-Options
      width: size,
      height: size,
      color: {r: 135, g: 135, b: 135},
      anticlockwise: true,
      borderWidth: 10,
      borderColor: "#313131"
    });

    demoColorPicker.on("color:change", function(color, changes) {
      // Log the color's hex RGB value to the dev console
      console.log(color.rgb);
      console.log(color.hsv.v);
      // If the "H" channel has changed, log the color's HSV value too
      //if (changes.h) {
      //  console.log(color.hsv);
      //}
      var json = {state:"ON",brightness:color.hsv.v,color:{mode:"rgb",r:color.rgb.r,g:color.rgb.g,b:color.rgb.b},mode:"SOLID"};
      console.log(json);
      console.log(JSON.stringify(json));

      $.ajax( "/api/v1/state", { data: JSON.stringify(json), dataType: "json", method: "POST", contentType: "application/json", cache: false, timeout: 2000})
        .done(function( data ) {
          console.log( "Response: " );
          console.log( data );
        })
        .fail(function( data ) {
          console.log( "Error: " );
          console.log( data );
        });
    });
  </script>
</main>
<footer class="footer">
      <div class="container">
        <span class="text-muted">LED Steuerung</span>
      </div>
    </footer>

    <script src="https://code.jquery.com/jquery-3.3.1.min.js" integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
</body>
</html>
)=====";
