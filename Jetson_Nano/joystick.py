import inputs

pads = inputs.devices.gamepads
val_dict = {"id": 0, "val": 0}

# ABS_X = 0
# ABS_Y = 1
# ABS_RX = 2
# ABS_RY = 3

if len(pads) == 0:
    raise Exception("Couldn't find any Gamepads!")


while True:
    events = inputs.get_gamepad()
    for event in events:
        # print(event.ev_type, event.code, event.state)
        if event.ev_type == "Absolute":
            print()
            if "ABS_R" in event.code:
                print(event.code, event.state)
                if event.code == "ABS_RX":
                    val_dict["id"] = 2
                    val_dict["val"] = event.state
                elif event.code == "ABS_RY":
                    val_dict["id"] = 3
                    val_dict["val"] = event.state
            elif "ABS_" in event.code:
                print(event.code, event.state)
                if event.code == "ABS_RX":
                    val_dict["id"] = 2
                    val_dict["val"] = event.state
                elif event.code == "ABS_RY":
                    val_dict["id"] = 3
                    val_dict["val"] = event.state
