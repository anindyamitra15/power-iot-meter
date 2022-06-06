import { Subscription } from 'rxjs';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import { Component, OnInit, OnDestroy } from '@angular/core';
import { AngularFireDatabase } from '@angular/fire/compat/database';
import Measurements from 'src/app/dtos/measurement.dto';

const TOPIC = '/users';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit, OnDestroy {
  authState?: Subscription;
  user: any;
  topicSub?: Subscription;
  dataSub?: Subscription;
  deviceTopic?: string;
  constructor(
    private rtdb: AngularFireDatabase,
    private auth: AngularFireAuth
  ) {

  }

  ngOnInit(): void {
    //check login, if so, subscribe to DB
    this.authState = this.auth.authState.subscribe(user => {
      this.user = user;
      if (user) {
        this.topicSub = this.rtdb
          .object(TOPIC + '/' + user.uid)
          .valueChanges()
          .subscribe(topic => {
            this.deviceTopic = topic as string;
            this.dataSub = this.rtdb
              .object(this.deviceTopic)
              .valueChanges()
              .subscribe(data => {
                this.dummy = data as Measurements;

              });
          });
      }
    });

  }

  ngOnDestroy(): void {
    //unsubscribe from DB
  }

  dummy: Measurements = {
    current_rms: 20.00,
    active_power: 1401.30,
    voltage_rms: 220.35,
    total_energy: 57.25,
    power_outages: {
      "2020-05-13 15:30": "2020-05-13 15:30",
      "2020-05-13 15:36": "2020-05-13 16:30",
      "2020-05-13 15:37": "2020-05-13 17:30",
      "2020-05-13 15:38": "2020-05-13 18:30",
    }
  }
  billRate: number = 6.00;
  getBill(): number {
    return this.dummy.total_energy * this.billRate;
  }

}
