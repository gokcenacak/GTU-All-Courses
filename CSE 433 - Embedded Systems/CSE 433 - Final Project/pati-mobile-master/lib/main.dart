import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:http/http.dart' as http;
import 'dart:async';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.portraitUp,
      DeviceOrientation.portraitDown,
    ]);

    return MaterialApp(
      title: 'Pati',
      theme: ThemeData(
        primarySwatch: Colors.teal,
      ),
      home: MyHomePage(title: 'Pati'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);
  final String title;
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String percentage = '';
  Timer timer;
  @override
  void initState(){
    super.initState();
    timer = Timer.periodic(Duration(seconds: 5), (Timer t) => checkForFoodPercentage());
  }
  @override
  void dispose() {
    timer?.cancel();
    super.dispose();
  }
  Future<String> getFoodPercentage() async {
    final response = await http.get('http://192.168.1.24/weight');

    if (response.statusCode == 200) {
      return response.body;
    } else {
      print('pati server could not respond');
    }
  }
  String removeLeadingZerosFromString(String s) {
    for (var i = 0; i < s.length; i++) {
      if (s[0] == '0' && s.length > 1) {
        s = s.substring(1);
      }
    }
    return s;
  }
  void checkForFoodPercentage() async {
    var response = await getFoodPercentage();
    response = removeLeadingZerosFromString(response);
    setState(() {
      percentage = response;
    });
  }
  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Container(
                padding: const EdgeInsets.all(1.0),
                child: new Text("pati",
                    style: TextStyle(
                      fontFamily: 'Mitr',
                      color: Color(0xFFFFC549),
                      fontSize: 35,
                      fontWeight: FontWeight.w400,
                      fontStyle: FontStyle.normal,
                      letterSpacing: 0,
                    )
                ),
            ),
            Image.asset(
              'assets/app_logo.png',
              fit: BoxFit.contain,
              height: 50,
            ),
          ],
        ),
        centerTitle: true,
      ),
      body: new SingleChildScrollView(
        child: new Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[

            Padding(
              padding: const EdgeInsets.only(right: 24, left: 24, top: 20),
              child: new Container(
                height: 130,
                decoration: new BoxDecoration(
                    color: Color(0xFFFFC549),
                    borderRadius: BorderRadius.circular(12),
                    border: Border.all(
                      color: Colors.teal,
                      width: 5,
                    ),
                ),
                child: new Stack(children: <Widget>[
                  new Align(
                      alignment: Alignment.topRight,
                      child: new Padding(
                        padding: const EdgeInsets.only(right: 45),
                        child: new Stack(children: <Widget>[
                          new Container(
                              child: Padding(
                                padding: const EdgeInsets.only(left: 24, top: 10),
                                child: Text(
                                  "Yaş: 2",
                                  style: TextStyle(
                                    fontFamily: 'NunitoSans',
                                    color: Colors.teal,
                                    fontSize: 20,
                                    fontWeight: FontWeight.w700,
                                    fontStyle: FontStyle.normal,
                                  ),
                                  textAlign: TextAlign.left,
                                ),
                              )
                          ),
                          new Container(
                              child: Padding(
                                padding: const EdgeInsets.only(left: 24, top: 35),
                                child: Text(
                                  "Cinsiyet: Dişi",
                                  style: TextStyle(
                                    fontFamily: 'NunitoSans',
                                    color: Colors.teal,
                                    fontSize: 20,
                                    fontWeight: FontWeight.w700,
                                    fontStyle: FontStyle.normal,
                                  ),
                                  textAlign: TextAlign.left,
                                ),
                              )
                          ),
                          new Container(
                              child: Padding(
                                padding: const EdgeInsets.only(left: 24, top: 60),
                                child: Text(
                                  "Tür: Kedi",
                                  style: TextStyle(
                                    fontFamily: 'NunitoSans',
                                    color: Colors.teal,
                                    fontSize: 20,
                                    fontWeight: FontWeight.w700,
                                    fontStyle: FontStyle.normal,
                                  ),
                                  textAlign: TextAlign.left,
                                ),
                              )
                          ),
                          new Container(
                              child: Padding(
                                padding: const EdgeInsets.only(left: 24, top: 85),
                                child: Text(
                                  "Cins: Van kedisi",
                                  style: TextStyle(
                                    fontFamily: 'NunitoSans',
                                    color: Colors.teal,
                                    fontSize: 20,
                                    fontWeight: FontWeight.w700,
                                    fontStyle: FontStyle.normal,
                                  ),
                                  textAlign: TextAlign.left,
                                ),
                              )
                          ),
                        ],
                        ),
                      )
                  ),
                  new Align(
                    alignment: Alignment.topLeft,
                    child: new Padding(padding: const EdgeInsets.only(left: 20, top: 15, bottom: 5),
                      child: new Image.asset(
                      'assets/cat.png',
                      height: 120,
                    )
                    )
                  )
                ],)

              ),
            ),
            Padding(
              padding: const EdgeInsets.only(right: 24, left: 24, top: 25),
              child: Container(
                height: 505,
                child: new Stack(children: <Widget>[
                  new Container(
                    decoration: new BoxDecoration(
                        color: Color(0xFFFFC549),
                        border: Border.all(
                          color: Colors.teal,
                          width: 5,
                        ),
                        borderRadius: BorderRadius.circular(12),

                    ),
                  ),
                  new Stack(children: <Widget>[
                    new Align(alignment: Alignment.topCenter,
                        child: Padding(
                          padding: const EdgeInsets.only(right: 24, left: 24, top: 10, bottom: 50),
                          child: Text(
                            "Ev",
                            style: TextStyle(
                              fontFamily: 'NunitoSans',
                              color: Colors.teal,
                              fontSize: 30,
                              fontWeight: FontWeight.w800,
                              fontStyle: FontStyle.normal,
                            ),
                            textAlign: TextAlign.left,
                          ),
                        )
                    ),

                    new Align(alignment: Alignment.topCenter,
                        child: Padding(
                          padding: const EdgeInsets.only(right: 24, left: 24, top: 50, bottom: 65),
                          child: Text(
                            "Ortam sıcaklığı: 30°C",
                            style: TextStyle(
                              fontFamily: 'NunitoSans',
                              color: Colors.teal,
                              fontSize: 20,
                              fontWeight: FontWeight.w700,
                              fontStyle: FontStyle.normal,
                            ),
                            textAlign: TextAlign.left,
                          ),
                        )
                    ),
                    new Align(alignment: Alignment.topCenter,
                        child: Padding(
                          padding: const EdgeInsets.only(right: 24, left: 24, top: 80, bottom: 65),
                          child: Text(
                            "Ortam nemi: 50%",
                            style: TextStyle(
                              fontFamily: 'NunitoSans',
                              color: Colors.teal,
                              fontSize: 20,
                              fontWeight: FontWeight.w700,
                              fontStyle: FontStyle.normal,
                            ),
                            textAlign: TextAlign.left,
                          ),
                        )
                    ),
                  ],),
                  new Align(
                    alignment: Alignment.center,
                    child: new Container(
                      width: 250,
                      height: 250,
                      decoration: new BoxDecoration(
                        color: Color(0xffffffff),
                        shape: BoxShape.circle,
                        border: Border.all(
                          color: Colors.teal,
                          width: 10,
                        )
                      ),
                      child: Center(
                        child: new Stack(children: <Widget>[
                          new Align(alignment: Alignment.center,
                              child: Padding(
                                padding: const EdgeInsets.only(right: 24, left: 24, top: 30, bottom: 50),
                                child: Text(
                                  '$percentage' + '%',
                                  style: TextStyle(
                                    fontFamily: 'NunitoSans',
                                    color: Colors.black,
                                    fontSize: 60,
                                    fontWeight: FontWeight.w700,
                                    fontStyle: FontStyle.normal,
                                  ),
                                  textAlign: TextAlign.left,
                                ),
                              )
                          ),

                          new Align(alignment: Alignment.bottomCenter,
                            child: Padding(
                              padding: const EdgeInsets.only(right: 24, left: 24, bottom: 65),
                              child: Text(
                                "Mama oranı",
                                style: TextStyle(
                                  fontFamily: 'NunitoSans',
                                  color: Colors.black,
                                  fontSize: 25,
                                  fontWeight: FontWeight.w700,
                                  fontStyle: FontStyle.normal,
                                ),
                                textAlign: TextAlign.left,
                              ),
                            )
                          ),
                        ],)


                    ),

                    ),
                  ),


                  new Align(
                    alignment: Alignment.bottomCenter,
                    child: Padding(
                      padding: const EdgeInsets.only(right: 24, left: 24, top: 30, bottom: 40),

                      child: GestureDetector(
                        onTap: () {
                          http.get("http://192.168.1.24/open");
                        },
                        child: new Container(
                          height: 63,
                          decoration: new BoxDecoration(
                              color: Colors.teal,
                              borderRadius: BorderRadius.circular(50)),
                          child: Center(
                            child: new Text(
                              "Mama Ekle",
                              style: TextStyle(
                                fontFamily: 'NunitoSans',
                                color: Colors.white,
                                fontSize: 20,
                                fontWeight: FontWeight.w700,
                                fontStyle: FontStyle.normal,
                              ),
                              textAlign: TextAlign.left,
                            ),
                          ),
                        ),
                      ),
                    )
                  )
                ]
                )
              ),
            ),
            Padding(
              padding: const EdgeInsets.only(right: 24, left: 24, top: 30),
            ),
          ],
        ),
      ),
    );
  }
}
