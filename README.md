# Requirement
* NDK
* Rooted android devices with NFC

# Instruction
1. Git clone the project to local.
    ```shell
    $ git clone https://github.com/ZoLArk173/Android_NFC_FIXED_UID.git
    $ cd Android_NFC_FIXED_UID
    // Since there are some parts of code belongs to other repositories, we need to clone them as well.
    $ git submodule init
    $ git submodule update
    ```

2. Change the desired ```UID``` inside ```Android_NFC_FIXED_UID/UidCtrl/main.cpp```

3. Inside ```Android_NFC_FIXED_UID/Application.mk```, change the ```APP_BUILD_SCRIPT := path/to/Android.mk``` to the path of ```Android.mk``` under project root folder.
    
    (ex: ``` APP_BUILD_SCRIPT := /home/zolark173/Documents/Android_NFC_FIXED_UID/Android.mk```)

4. Run ```ndk-build NDK_PROJECT_PATH=/path/to/proj NDK_APPLICATION_MK=/path/to/Application.mk``` to build the project.
    * Note that change ```/path/to/proj``` to the path of this project, and ```/path/to/Application.mk``` to the absolute path of ```/Android_NFC_FIXED_UID/Application.mk```.

5. If there is no error, you will get ```injecter``` and ```libuildctrl.so``` under ```/Android_NFC_FIXED_UID/libs```, with 32-bit and 64-bit version.

6. Send two files to your android device under ```/data/local/tmp/```.

7. Run ```/data/local/tmp/injector com.android.nfc /data/local/tmp/libuidctrl.so``` with root privilege.
    ```shell
    $ adb shell
    $ su
    $ /data/local/tmp/injector com.android.nfc /data/local/tmp/libuidctrl.so
    ```

# Usage
Tested on TicWatch Pro 2020 with wearOS 2 (which is base on Android Pie).

UID will remain the same as long as NFC process doesn't restart.
    
