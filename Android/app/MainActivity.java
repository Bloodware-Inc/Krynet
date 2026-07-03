package com.krynet;

import android.os.Bundle;
import android.view.WindowManager;
import com.sciter.support.SciterActivity; // Assumes Sciter SDK android library dependency

public class MainActivity extends SciterActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // Force full screen native app client look
        getWindow().setFlags(
            WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED,
            WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED
        );
        
        super.onCreate(savedInstanceState);
        
        // Pass network isolation & software layer configurations if needed via JNI
        setAssetPath("file:///android_asset/www/");
        loadUrl("https://krynet.ai");
    }

    static {
        System.loadLibrary("krynet_native");
    }
}
