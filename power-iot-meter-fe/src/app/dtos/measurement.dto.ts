export default interface Measurements {
    current_rms: number,
    active_power: number,
    voltage_rms: number,
    total_energy: number,
    power_outages: {
        [key: string]: string
    }
}