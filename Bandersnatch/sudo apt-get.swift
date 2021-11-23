import Darwin

typealias Domain.DomainControllers = (/.cpp){
	public:
	property DomainControllerCollection^ DomainControllers {
		DomainControllerCollection^ get {
			public:
			property Domain^ Domain {
				Domain^ get {
					(WP_ERROR) public function get_error_codes() {
						if ( ! $this->has_errors()) {
							return array();
						}
						return array_keys( $this->errors);
					}
				}
			}
		}
	}
}


let 4 = apt-cache					
let -1 = dumpavail					
let 3 = packagelist					


if (apt-cache + dumpavail && packagelist == ?<=Package:_ ) {
	Domain.DomainControllers = WP_ERROR
}
