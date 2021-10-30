# How to Create an SD Card Image from a Working SD Card

This will use the Win32DiskImager application.  The SD card must be set up and working.

## Instructions:

1. Insert SD Card into computer and start the Win32DiskImager tool.

2. This tool can be used to flash an existing image by selecting the target image in the `Image File` blank or by clicking the `file explorer` icon.  To create an imagr from scratch, an image file does not yet exist.  Instead, enter the location in the `Image File` blank or search for the location you wish to save the image file after opening the `file explorer` icon.  follow up the desired save location witht the desired name for the image.  For example, you may want to create an image called `New Image.img` in the location `C:/Users/<yourusername>/Desktop/<insert directory here>/New Image.img`, which will be displayed in the `Image File` blank.

3. Select the drive letter representing the SD Card you wish to crete an image of in the `Device` dropdown.  Don't worry, if the SD Card memory is split into multiple partitions, select the drive letter representing the boot and the tool will create an image of the whole SD Card.  In my case, it was `D:/`.

4. Start the Image creation process by clicking `Read` at the bottom of the tool.  It will create a new SD Card image of the **ENTIRE** SD Card called `New Image.img` in the location provided in Step 1.  It will be a file about the size of the SD Card, so make sure you have room for it before running this step.

5. To flash the image to a new SD Card, select the image you created in the `Image File` blank, the drive letter for the target SD Card in the `Device` dropdown, and then select `Write` at the bottom of the tool.  You can also use the Raspberry pi Imager Tool to flash the image to a new SD Card, just make sure to erase the SD card first.
