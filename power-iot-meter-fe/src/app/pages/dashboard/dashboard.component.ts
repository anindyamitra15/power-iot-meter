import { Subscription } from 'rxjs';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import { Component, OnInit, OnDestroy } from '@angular/core';
import { AngularFireDatabase } from '@angular/fire/compat/database';

const TOPIC = '/test';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit, OnDestroy {
  authState?: Subscription;
  user: any;
  dataSub?: Subscription;
  constructor(
    private rtdb: AngularFireDatabase,
    private auth: AngularFireAuth
  ) {
    //check login, if so, subscribe to DB
    this.authState = this.auth.authState.subscribe(user => {
      this.user = user;
      if (user) {
        this.dataSub = this.rtdb.object(TOPIC).valueChanges().subscribe(data => console.log(data));
      }
    });
  }

  ngOnInit(): void {
  }

  ngOnDestroy(): void {
    //unsubscribe from DB
  }

  dummy = {
    current_rms: 20.00,
    active_power: 1401.30,
    voltage_rms: 220.35,
    energy_consumed: 57.25,
    power_outage: {
      "2020-05-13 15:30": "2020-05-13 15:30",
      "2020-05-13 15:36": "2020-05-13 16:30",
      "2020-05-13 15:37": "2020-05-13 17:30",
      "2020-05-13 15:38": "2020-05-13 18:30",
    }
  }
  billRate: number = 6.00;
  getBill(): number {
    return this.dummy.energy_consumed * this.billRate;
  }

}
