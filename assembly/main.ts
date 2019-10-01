declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export class Viewer3DAPI {
  constructor(root, App) {
    const __app = new App(root);
    this.root = root;
    this.getApp = () => __app;
  }

  initMap(mapData, ringsData, updateMapLoadingInfo, balloonOnClick) {
    this.getApp()
      .attach();
    this.getApp()
      .selector
      .registerClickCallback(balloonOnClick);
    this.getApp()
      .createProgressProcessor();
    this.getApp()
      .getProgressProcessor()
      .setOnUpdate(updateMapLoadingInfo);
    this.getApp()
      .getProgressProcessor()
      .setOnReady(updateMapLoadingInfo);
    this.getApp()
      .importConfig(mapData, true);
    if (ringsData) {
      ringsData.rings.forEach(ringObj => this.updateRing(ringObj));
    }

    const infoblockImg = document.createElement('img');
    infoblockImg.src = '/assets/go_button.png';
    const infoblockImgWrapper = document.getElementById("infoblock__image");
    infoblockImgWrapper.appendChild(infoblockImg);

  }

  showTicketsHereBalloon(sectionID, rowNumber) {
    this.getApp()
      .showTicketsBalloon(sectionID, rowNumber);
  }

  hideTicketsHereBalloon() {
    this.getApp().hideTicketsBalloon();
  }

  hideInfoblock() {
    document.getElementById('infoblock').style.display = 'none';
  }

  setHelicopterView() {
    this.getApp()
      .setHelicopterView();
  }

  setDefaultView() {
    this.getApp().setDefaultView();
  }

  setSectionView(sectionID, rowNumber, seatNumber) {
    this.getApp()
      .setSectionView(sectionID, rowNumber, seatNumber);
  }

  set360View(bool) {
    this.getApp().set360View(bool);
  }

  showRing(ringID) {
    this.getApp()
      .config
      .customObject
      .find(obj => obj._id_ === ringID).visible = true;
  }

  hideRing(ringID) {
    this.getApp()
      .config
      .customObject
      .find(obj => obj._id_ === ringID).visible = false;
  }

  makeScreenshot(seatInfo, callback) {
    this.getApp()
      .setSectionView(
        seatInfo.sectionID,
        seatInfo.rowNumber,
        seatInfo.seatNumber,
        callback,
      );
  }

  setGraphicsMode(mode) {
    this.getApp().viewController.setGraphicsMode(mode);
  }

  updateRing(ringObj) {
    const ring = this.getApp()
      .config
      .customObject
      .find(obj => obj._id_ === Number(ringObj.id));
    if (ring) {
      const config = { ...ring._config() };
      config.torusText = ringObj.text;
      if (ringObj.colour === 'green') {
        config.primaryColor = '#00ff00';
      } else if (ringObj.colour === 'red') {
        config.primaryColor = '#ff0000';
      } else if (ringObj.colour === 'orange') {
        config.primaryColor = '#fc6600';
      } else {
        config.primaryColor = ringObj.colour;
      }
      this.getApp()
        .build({
          type: 'customObject',
          config,
        });
    }
  }

  updateRingQuarters(ringID, quartersAmount) {
    const ring = this.getApp()
      .config
      .customObject
      .find(obj => obj._id_ === ringID);
    if (ring) {
      ring.mesh.activateQuarters(quartersAmount);
    }
  }

  showDealChanges(ringID, rank, text) {
    const ring = this.getApp()
      .config
      .customObject
      .find(obj => obj._id_ === ringID);
    if (ring) {
      const rankColor = `#${ring.mesh.primaryColor.getHexString()}`;
      const { x, y } = this.getApp().viewController.toScreenPosition(ring);

      const infoBlock = document.createElement('div');
      infoBlock.style.display = 'none';
      infoBlock.style.position = 'absolute';
      infoBlock.style.left = '0px';
      infoBlock.style.top = '0px';
      infoBlock.style.width = '100px';
      infoBlock.style.height = '100px';
      infoBlock.style.backgroundColor = 'rgba(0, 0, 0, 0)';
      infoBlock.style.fontFamily = 'Roboto';
      infoBlock.style.overflow = 'hidden';
      this.root.appendChild(infoBlock);

      const infoWrapper = document.createElement('div');
      infoWrapper.style.animation = 'infoAppearing 3s cubic-bezier(0.175, 0.885, 0.32, 1.275) 0s 1';


      const rankCircle = document.createElement('div');
      rankCircle.style.width = '50px';
      rankCircle.style.height = '50px';
      rankCircle.style.backgroundColor = rankColor;
      rankCircle.style.borderRadius = '50%';
      rankCircle.style.margin = '0 auto';
      rankCircle.style.color = 'white';
      rankCircle.style.display = 'flex';
      rankCircle.style.justifyContent = 'center';
      rankCircle.style.alignItems = 'center';
      rankCircle.style.fontSize = '1.6em';

      const rankCircleText = document.createElement('div');
      rankCircleText.innerText = rank;

      rankCircle.appendChild(rankCircleText);
      infoWrapper.appendChild(rankCircle);

      const infoTextWrapper = document.createElement('div');
      infoTextWrapper.style.width = '100px';
      infoTextWrapper.style.height = '100px';
      infoTextWrapper.style.display = 'flex';
      infoTextWrapper.style.justifyContent = 'center';
      infoTextWrapper.style.fontSize = '1.2em';
      infoTextWrapper.style.color = 'white';

      const infoText = document.createElement('div');
      infoText.innerText = text;

      infoTextWrapper.appendChild(infoText);
      infoWrapper.appendChild(infoTextWrapper);

      infoBlock.appendChild(infoWrapper);
      infoBlock.style.left = `${x - 100 / 2}px`;
      infoBlock.style.top = `${y - 75}px`;
      infoBlock.style.display = 'block';

      this.getApp().viewController.dealsAnimations.set(ringID, () => {
        const { x, y } = this.getApp().viewController.toScreenPosition(ring);
        infoBlock.style.left = `${x - 100 / 2}px`;
        infoBlock.style.top = `${y - 75}px`;
      });

      setTimeout(() => {
        this.getApp().viewController.dealsAnimations.delete(ringID);
        this.root.removeChild(infoBlock);
      }, 2500);
    }
  }

  resizeScene() {
    this.getApp().viewController.dimensionsUpdate();
  }
}