package com.xzy.myjnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private TextView mText;
    private Button mBut;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mText = (TextView) findViewById(R.id.text);
        mBut = (Button) findViewById(R.id.button);
        mText.setText("myJniTest"+JNIMethod.avcoder_find_decoder(28));
    }


    public void transcode(View v){

        String[] commands = new String[9];
        commands[0] = "ffmpeg";
        commands[1] = "-y";
        commands[2] = "-i";
        commands[3] = "/storage/emulated/0/appwonderroot/v/raw/vedio-1586478489.mp4";
        commands[4] = "-r";
        commands[5] = "1";
        commands[6] = "-f";
        commands[7] = "image2";
        commands[8] = "/storage/emulated/0/appwonderroot/v/cps/foo-%03d.jpeg";
        int result = JNIMethod.run(commands);
        if(result == 0){
            Toast.makeText(MainActivity.this, "命令行执行完成", Toast.LENGTH_SHORT).show();
        }

    }
}
