/* 
1. Use the inquirer npm package to get user input.
2. Use the qr-image npm package to turn the user entered URL into a QR code image.
3. Create a txt file to save the user input using the native fs node module.
*/

import inquirer from "inquirer";
import qr from "qr-image";
import fs from "fs";

inquirer.prompt([
    {
        message: "Type Your URL: ",
        name: "URL",
    }
]).then((answers) => {
    console.log(answers);
    const url = answers.URL;
    var qr_svg = qr.image(url);
    qr_svg.pipe(fs.createWriteStream("qr_image.png"));
}).catch((err) => {
    if (err.isTtyError) {

    }
    else {

    }
})