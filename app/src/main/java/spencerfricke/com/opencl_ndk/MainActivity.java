package spencerfricke.com.opencl_ndk;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        onCreateNDK(this);
    }

    @Override
    public void onPause () {
        super.onPause();
        onPauseNDK();
    }

    @Override
    public void onResume() {
        super.onResume();
        ((TextView)findViewById(R.id.display_text)).setText(stringFromJNI());
        onResumeNDK();
    }

    static {
        System.loadLibrary("opencl_ndk");
    }

    public native String stringFromJNI();
    public native void onCreateNDK(Activity callerActivity);
    public native void onPauseNDK();
    public native void onResumeNDK();
}