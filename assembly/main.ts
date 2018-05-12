let groupArray: string[][] = [['CIT-14a', 'CIT-14b', 'CIT-24a', 'CIT-24b', 'CIT-34'],
    ['CIT-15a', 'CIT-15b', 'CIT-25a', 'CIT-25b', 'CIT-35'],
    ['CIT-16a', 'CIT-16b', 'CIT-26a', 'CIT-26b', 'CIT-26c', 'CIT-36'],
    ['CIT-17a', 'CIT-17b', 'CIT-27a', 'CIT-27b', 'CIT-27c', 'CIT-37']];
let dayArray: string[] = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday'];
let timeArray: string[] = ['8:30 - 10:05', '10.25 — 12.00', '12.35 — 14.10', '14.30 — 16.05', '16.25 — 18.00'];
let practiceArray: string[][] = [['Sound and images', 'Mobile development', 'Server development', 'Parallel programming'],
    ['Computer architecture', 'Computer systems', 'Computational intelligence'],
    ['Computer circuitry', 'Database organization', 'IT management', 'Probability theory', 'Computer graphic'],
    ['Programming']];
let freeAudience: string[] = ['19', '20', '21', '22', '25a', '25b', '313', '310'];
let schedule: ScheduleItem[] = [];

class ScheduleItem {
  group: string;
  day: string;
  time: string;
  subject: string;
  audience: string;

    constructor(group: string, day: string, time: string, subject: string, audience: string) {
        this.group = group;
        this.day = day;
        this.time = time;
        this.subject = subject;
        this.audience = audience;
    }
}

function checkOnUnique(group: string, day: string, time: string, subject: string, audience: string): bool {
    for (let i = 0; i < schedule.length; i++) {
       if ((schedule[i].group === group && schedule[i].subject === subject)
           || (schedule[i].time === time && schedule[i].day === day && schedule[i].subject === subject)
           || (schedule[i].time === time && schedule[i].day === day && schedule[i].audience === audience)
           || (schedule[i].time === time && schedule[i].day === day && schedule[i].group === group)) {
           return false;
       }
    }
    return true;
}

function sortFromGroup(schedule: ScheduleItem[]): Map<void, ScheduleItem> {
    let groups = new Map();
    for (let i = 0; i < groupArray.length; i++) {
        for (let j = 0; j < groupArray[i].length; j++) {
            groups.set(groupArray[i][j], schedule.filter((item: ScheduleItem): bool => item.group === groupArray[i][j]));
        }
    }
    return groups;
}

export function createSchedule(): void {
    // console.time('create schedule');
    for (let day = 0; day < dayArray.length; day++) {
        for (let thread = 0; thread < groupArray.length; thread++) {
            for (let subject = 0; subject < practiceArray.length; subject++) {
                for (let time = 0; time < timeArray.length; time++) {
                    for (let group = 0; group < groupArray[thread].length; group++) {
                        for (let audience = 0; audience < freeAudience.length; audience++) {
                            if (!!practiceArray[thread][subject] && !!groupArray[thread][group] && checkOnUnique(groupArray[thread][group], dayArray[day], timeArray[time], practiceArray[thread][subject], freeAudience[audience])) {
                                schedule.push(new ScheduleItem(groupArray[thread][group], dayArray[day], timeArray[time], practiceArray[thread][subject], freeAudience[audience]));
                            }
                        }
                    }
                }
            }
        }
    }
    // console.clear();
    // console.log(schedule);

    let newGroups: Map<void, ScheduleItem> = sortFromGroup(schedule);
    // console.log(groups);

    // document.querySelector('.schedule').innerHTML += schedule;

    // console.timeEnd('create schedule');
};

