2d_Engine/
├── include/
│   └── engine/
│       ├── engine.h
│       ├── core/              
│       │   ├── types.h         # Entity, IDs, handles
│       │   ├── math.h          # Vec2, Rect, helpers
│       │   ├── arena.h         
│       │   └── log.h           # logging
│       ├── ecs/
│       │   ├── world.h
│       │   ├── component.h
│       │   └── system.h
│       ├── platform/           
│       │   ├── window.h
│       │   ├── input.h
│       │   ├── time.h
│       │   └── audio.h
│       ├── render/
│       │   ├── renderer.h
│       │   ├── camera.h
│       │   ├── sprite.h
│       │   ├── tilemap.h
│       │   └── texture.h
│       ├── assets/
│       │   ├── asset_manager.h
│       │   └── image.h
│       └── components/         
│           └── components.h
│
├── src/
│   ├── core/
│   │   ├── math.c
│   │   ├── arena.c
│   │   └── log.c
│   ├── ecs/
│   │   ├── world.c
│   │   └── system.c
│   ├── platform/
│   │   ├── sdl_window.c        
│   │   ├── sdl_input.c
│   │   ├── sdl_time.c
│   │   └── sdl_audio.c
│   ├── render/
│   │   ├── renderer.c
│   │   ├── camera.c
│   │   ├── sprite.c
│   │   ├── tilemap.c
│   │   └── texture.c
│   ├── assets/
│   │   ├── asset_manager.c
│   │   └── image.c
│   └── engine/
│       └── engine.c          
│
├── game/                     
│   ├── include/
│   │   └── game/
│   │       ├── game.h
│   │       └── components.h
│   ├── src/
│   │   ├── game.c
│   │   ├── systems/
│   │   │   ├── movement_system.c
│   │   │   ├── damage_system.c
│   │   │   └── ai_system.c
│   │   └── entities/
│   │       ├── player.c
│   │       └── enemy.c
│   └── assets/
│       ├── textures/
│       ├── fonts/
│       └── sounds/
│
├── third_party/               
├── tests/
│   ├── test_ecs.c
│   └── test_math.c
├── main.c
├── Makefile
└── README.md
