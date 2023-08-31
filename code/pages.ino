String page(String page_ssid, String page_password, String page_message, String page_interval){
  return "<!DOCTYPE html>\
<html lang='en'>\
<head>\
    <meta charset='UTF-8'>\
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\
    <title>Document</title>\
    <style>\
        *{\
            font-family: Arial, Helvetica, sans-serif;\
            font-style: normal;\
            box-sizing: border-box;\
            background-color: #333;\
        }\
        label {\
            margin: 10px 0;\
            color: aliceblue;\
        }\
        h2{\
            margin-left: 10px;\
        }\
        fieldset{\
            display: flex;\
            flex-direction: column;\
            border: none !important;\
        }\
        input{\
            border: none;\
            border-radius: 4px;\
            padding: 3px;\
            background-color: aliceblue;\
        }\
        button{\
            width: fit-content;\
            display: flex;\
            justify-content: center;\
            align-items: center;\
            margin: 30px auto;\
            padding: 10px;\
            font-size: larger;\
            font-weight: 700;\
            border: none;\
            border-radius: 4px;\
            background-color: yellowgreen;\
        }\
        #reset{\
            background-color: red !important;\
            color: white !important;\
            font-size: smaller !important;\
        }\
        @media only screen and (min-width: 600px) {\
            form{\
                width: 500px;\
                justify-content: center;\
                margin: auto;\
            }\
        }\
    </style>\
</head>\
<body>\
    <form action='/' method='POST'>\
        <h2>WiFi Ayarlari</h2>\
        <fieldset>\
            <label for=''>WiFi Ismi</label>\
            <input type='text' name='ssid' value='" + page_ssid + "' placeholder='SUPERONLINE_WIFI_XXXX...' maxlength=50>\
            <label for=''>WiFi Sifresi</label>\
            <input type='text' name='password' value='" + page_password + "' placeholder='1A125w354...' maxlength=50>\
        </fieldset>\
        <h2>Mesaj ayarlari</h2>\
        <fieldset>\
            <label for=''>Gonderilecek Mesaj (Maximum 50 karakter)</label>\
            <input type='text' name='message' value='" + page_message + "' placeholder='Yardima ihtiyacim var' maxlength=50>\
            <label for=''>Mesaj Gonderim Araligi (Saniye cinsinden)</label>\
            <input type='number' name='interval' value='" + page_interval + "' placeholder='5 yazilinca 5 saniyede bir mesaj' min=0 max=180>\
            <button type='submit'>Degisiklikleri Kaydet</button>\
        </fieldset>\
    </form>\
    <form action='/reset' method='POST'>\
        <label for=''>Degisiklikler kaydedildikten sonra yeniden baslat butonuna tiklayin</label>\
        <button type='submit' id='reset'>Cihazi yeniden baslat</button>\
    </form>\
</body>\
</html>";
}